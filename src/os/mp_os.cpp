#include <signal.h>
#include <iostream>
#include <map>
#include "mp_os.h"

MP_OS* MP_OS::os = NULL;

MP_OS::MP_OS(MP_Scheduler::schedule algo, int usec_quantum, std::string fileName) {
  os            = this;
  m_os_thread   = new MP_Thread();
  m_scheduler   = new MP_Scheduler(algo);
  m_dispatcher  = new MP_Dispatcher(m_os_thread);
  m_quantum     = usec_quantum;
  m_quantum_exp = false;
  fileNameBackup = fileName;
this->mp_logger = new MP_Logger(fileName);

  setup_interrupt_handler();
}

void MP_OS::thread_create(void (*start_routine)(), std::string label) {
  MP_Thread *thread = new MP_Thread(start_routine, m_os_thread, label);
  m_scheduler->add_ready(thread);
  m_user_threads.push(thread);
}

void MP_OS::ReSchedule()
{
	std::ifstream file = mp_logger->ReadFile();
	std::string line;
	std::queue<MP_Thread*> copy = m_user_threads;
	std::map<std::string, MP_Thread*> thread_map;
	while(!copy.empty()){
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
		if(label == "")
		{
			break;
		}
		std::cout << thread_map[label]->getLabel() << std::endl;
		m_scheduler->add_ready(thread_map[label]);
	}
	thread_map.clear();
}

void MP_OS::wait()
{

int scheduleAlgo = m_scheduler->get_schedule_algo();
if(scheduleAlgo == MP_Scheduler::RERUN_FCFS || scheduleAlgo == MP_Scheduler::RERUN_ROUND_ROBIN)
{
	std::cout << "RERUN BEGIN" << std::endl;
	ReSchedule();
}

try
{
  while (m_scheduler->has_ready_threads())
  {
    MP_Thread *next_thread = m_scheduler->get_next_thread();
    mp_logger->log<MP_Thread>(*next_thread);
    next_thread->set_status(MP_Thread::RUNNING);

    start_quantum_timer();
    m_dispatcher->execute_thread(next_thread);
    stop_quantum_timer();

    MP_Thread::MP_Status status = m_quantum_exp ? MP_Thread::FINISHED : MP_Thread::WAITING;
    if(scheduleAlgo == MP_Scheduler::RERUN_FCFS || scheduleAlgo == MP_Scheduler::FCFS)
    {
	status = MP_Thread::FINISHED;
    }
    next_thread->set_status(status);
    if(status == MP_Thread::FINISHED)
    {
	std::string label = next_thread->getLabel();
	std::cout<< label<<std::endl;
	m_scheduler->RemoveThread(label);
    }	

    handle_finished_threads();
  }
}
catch(std::exception& e)
{
	LogStackTrace();
}
}

void MP_OS::PrepareRecoveryFromSegFault()
{
	struct sigaction sa, osa;
	sa.sa_handler = interrupt_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags=0; //or set to SA_SIGINFO
	sigaction(SIGSEGV, &sa, &osa);
}

void MP_OS::LogStackTrace()
{
        MemoryDumper* mpDump = new MemoryDumper();
        //log memeory and stacktrace information
        mp_logger->log<std::string>(GetStackTrace());
        mp_logger->log<long long>(mpDump->GetCurrentVirtualMemory());
        delete mpDump;
        mpDump = NULL;
}

void MP_OS::handle_finished_threads() {
  // TODO Memory Manager
  // iterate over m_user_threads
  // if any of them have a FINISHED status
  //    deallocate them (via memory manager)
}

void MP_OS::setup_interrupt_handler() {
  struct sigaction act, oact;
  act.sa_handler = interrupt_handler;
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;
  sigaction(SIGALRM, &act, &oact);

  PrepareRecoveryFromSegFault();
}

void MP_OS::start_quantum_timer() {
  set_quantum_timer(m_quantum);
}

void MP_OS::stop_quantum_timer() {
  set_quantum_timer(0);
}

void MP_OS::set_quantum_timer(int time) {
  if (m_scheduler->needs_quantum()) {
    std::cout<<"has quantum set"<< std::endl;

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

void MP_OS::interrupt_handler(int i) {
  if(i == SIGALRM)
  {
    os->quantum_expired();
  }
  else if(i == SIGSEGV)
  {
    os->LogStackTrace();
    exit(0);
  }
}
