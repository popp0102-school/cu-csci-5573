#include "mp_os.h"

#include <signal.h>
#include <iostream>
#include <exception>

MP_OS* MP_OS::os = NULL;

MP_OS::MP_OS(MP_Scheduler::schedule algo, int usec_quantum, string filename) {
  os               = this;
  m_os_thread      = new MP_Thread();
  m_scheduler      = new MP_Scheduler(algo, usec_quantum, filename);
  m_dispatcher     = new MP_Dispatcher(m_os_thread);
  m_memory_manager = new MP_MemoryManager();
  m_logger         = new MP_Logger("errors.txt");
  m_quantum_exp    = true;

  setup_interrupt_handlers();
}

void MP_OS::thread_create(void (*start_routine)(), string label) {
  MP_Thread *thread = new MP_Thread(start_routine, m_os_thread, label);
  m_scheduler->add_ready(thread);
}

void MP_OS::wait() {
  try {
    while (m_scheduler->has_ready_threads()) {
      MP_Thread *next_thread = m_scheduler->get_next_thread();
      next_thread->set_status(MP_Thread::RUNNING);

      start_quantum_timer(next_thread->get_quantum());
      m_dispatcher->execute_thread(next_thread);
      stop_quantum_timer();

      MP_Thread::MP_Status status = m_quantum_exp ? MP_Thread::WAITING : MP_Thread::FINISHED;

      next_thread->set_status(status);
      handle_finished_threads(next_thread);
    }
  } catch(exception& e) {
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

void MP_OS::log_stacktrace() {
  MemoryDumper* mpDump = new MemoryDumper();
  m_logger->log<string>(GetStackTrace());
  m_logger->log<long long>(mpDump->GetVirtualMemoryFromThread());
  m_logger->log<long long>(mpDump->GetCurrentVirtualMemory());
  m_logger->log<int>(mpDump->GetTotalVirtualMemory());
  m_logger->log<double>(mpDump->CPU_Percentage());
  delete mpDump;
  mpDump = NULL;
}

void MP_OS::handle_finished_threads(MP_Thread *thread) {
  if(thread->get_status() != MP_Thread::FINISHED) {
    return;
  }

  string label = thread->getLabel();
  m_scheduler->clear_thread(label);
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
  m_quantum_timer.it_interval.tv_sec  = 0;
  m_quantum_timer.it_interval.tv_usec = time;
  m_quantum_timer.it_value.tv_sec     = 0;
  m_quantum_timer.it_value.tv_usec    = time;

  setitimer(ITIMER_REAL, &m_quantum_timer, NULL);
}

void MP_OS::quantum_expired() {
  m_quantum_exp = true;
  stop_quantum_timer();

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

