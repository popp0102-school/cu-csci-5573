#include <signal.h>
#include <iostream>

#include "mp_os.h"

MP_OS* MP_OS::os = NULL;

MP_OS::MP_OS(MP_Scheduler::schedule algo, int usec_quantum, string fileName) {
  os            = this;
  m_os_thread   = new MP_Thread();
  m_scheduler   = new MP_Scheduler(algo);
  m_dispatcher  = new MP_Dispatcher(m_os_thread);
  m_quantum     = usec_quantum;
  m_quantum_exp = false;
  this.mp_logger = new MP_Logger(m_os_thread, fileName);

  setup_interrupt_handler();
}

void MP_OS::thread_create(void (*start_routine)(), string label) {
  MP_Thread *thread = new MP_Thread(start_routine, m_os_thread, label);
  m_scheduler->add_ready(thread);
  m_user_threads.push(thread);
}

void MP_OS::wait() {
	try{
		
	
  while (m_scheduler->has_ready_threads()) {
    MP_Thread *next_thread = m_scheduler->get_next_thread();
	mp_logger->log<MP_Thread>(*next_thread);
    next_thread->set_status(MP_Thread::RUNNING);

    start_quantum_timer();
    m_dispatcher->execute_thread(next_thread);
    stop_quantum_timer();

    MP_Thread::MP_Status status = m_quantum_exp ? MP_Thread::FINISHED : MP_Thread::WAITING;
    next_thread->set_status(status);

    handle_finished_threads();
  }
}catch(exception& e){
	//log memeory and stacktrace information

}
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
}

void MP_OS::start_quantum_timer() {
  set_quantum_timer(m_quantum);
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

void MP_OS::interrupt_handler(int i) {
  if(i == SIGALRM) {
    os->quantum_expired();
  }
}

