#include <signal.h>
#include <iostream>
#include <map>
#include "mp_os.h"

MP_OS* MP_OS::os = NULL;

MP_OS::MP_OS(MP_Scheduler::schedule algo, int usec_quantum, std::string filename) {
  os               = this;
  m_os_thread      = new MP_Thread();
  m_scheduler      = new MP_Scheduler(algo, usec_quantum);
  m_dispatcher     = new MP_Dispatcher(m_os_thread);
  m_memory_manager = new MP_MemoryManager();
  m_logger         = new MP_Logger(filename);
  m_quantum_exp    = true;

  setup_interrupt_handlers();
}

void MP_OS::thread_create(void (*start_routine)(), std::string label) {
  MP_Thread *thread = new MP_Thread(start_routine, m_os_thread, label);
  m_scheduler->add_ready(thread);
  m_user_threads.push(thread);
}

void MP_OS::wait() {
  int scheduleAlgo = m_scheduler->get_schedule_algo();
  if(scheduleAlgo == MP_Scheduler::RERUN_FCFS || scheduleAlgo == MP_Scheduler::RERUN_ROUND_ROBIN) {
    std::cout << "RERUN BEGIN" << std::endl;
    ReSchedule();
  }

  try {
    while (m_scheduler->has_ready_threads()) {
      MP_Thread *next_thread = m_scheduler->get_next_thread();
      m_logger->log<MP_Thread>(*next_thread);
      next_thread->set_status(MP_Thread::RUNNING);

      start_quantum_timer(next_thread->get_quantum());
      m_dispatcher->execute_thread(next_thread);
      stop_quantum_timer();

      MP_Thread::MP_Status status = m_quantum_exp ? MP_Thread::WAITING : MP_Thread::FINISHED;

      next_thread->set_status(status);
      handle_finished_threads(status, next_thread);
    }
  } catch(std::exception& e) {
    log_stacktrace();
  }
}

void* MP_OS::mp_malloc(int numbytes) {
  MP_Thread *currentThread = m_dispatcher->get_running_thread();
  return m_memory_manager->allocate(numbytes, currentThread);
}

void MP_OS::mp_free(void *mem) {
  MP_Thread *currentThread = m_dispatcher->get_running_thread();
  return m_memory_manager->deallocate(currentThread, mem);
}

void MP_OS::ReSchedule() {
  std::ifstream file = m_logger->ReadFile();
  std::string line;
  std::queue<MP_Thread*> copy = m_user_threads;
  std::map<std::string, MP_Thread*> thread_map;
  while(!copy.empty()) {
    MP_Thread *element = copy.front();
    thread_map[element->getLabel()] = element;
    copy.pop();
  }

  m_scheduler->clear_ready();
  std::cout << "m_scheduler clear" << std::endl;
  while(std::getline(file, line)){
    std::istringstream iss(line);
    std::string label;
    if(!(iss >> label)){
      std::cout << "ERROR READING IN LINE" << std::endl;
      break;
    }
    if(label == "") {
      break;
    }
    std::cout << thread_map[label]->getLabel() << std::endl;
    m_scheduler->add_ready(thread_map[label]);

  }
  thread_map.clear();
}

void MP_OS::log_stacktrace() {
  MemoryDumper* mpDump = new MemoryDumper();
  m_logger->log<std::string>(GetStackTrace());
  m_logger->log<long long>(mpDump->GetCurrentVirtualMemory());
  delete mpDump;
  mpDump = NULL;
}

void MP_OS::handle_finished_threads(MP_Thread::MP_Status status, MP_Thread *thread) {
  if(status != MP_Thread::FINISHED) {
    return;
  }

  std::string label = thread->getLabel();
  m_scheduler->RemoveThread(label);
  m_memory_manager->deallocate(thread); // garbage collection
}

void MP_OS::start_quantum_timer(int quantum) {
  if(quantum == -1) {
    return;
  }

  m_quantum_exp = false;
  set_quantum_timer(quantum);
}

void MP_OS::stop_quantum_timer() {
  set_quantum_timer(0);
}

void MP_OS::set_quantum_timer(int time) {
  if (m_scheduler->needs_quantum()) {
    m_quantum_timer.it_interval.tv_sec  = 0;
    m_quantum_timer.it_interval.tv_usec = time;
    m_quantum_timer.it_value.tv_sec     = 0;
    m_quantum_timer.it_value.tv_usec    = time;

    setitimer(ITIMER_REAL, &m_quantum_timer, NULL);
  }
}

void MP_OS::quantum_expired() {
  stop_quantum_timer();
  m_quantum_exp = true;
  MP_Thread *running_thread = m_dispatcher->get_running_thread();
  m_scheduler->add_ready(running_thread);
  m_dispatcher->context_switch();
}

void MP_OS::setup_interrupt_handlers() {
  setup_context_switch_interrupt_handler();
  segfault_recovery();
}

void MP_OS::setup_context_switch_interrupt_handler() {
  struct sigaction act, oact;
  act.sa_handler = context_switch_interrupt_handler;
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;
  sigaction(SIGALRM, &act, &oact);
}

void MP_OS::segfault_recovery() {
  struct sigaction sa, osa;
  sa.sa_handler = exception_handlers;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0;
  sigaction(SIGSEGV, &sa, &osa);
}
void MP_OS::context_switch_interrupt_handler(int i) {
  os->quantum_expired();
}

void MP_OS::exception_handlers(int i ) {
  if(i == SIGSEGV) {
    os->log_stacktrace();
    exit(0);
  }
}

