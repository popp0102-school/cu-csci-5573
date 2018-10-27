#include "mp_os.h"

MP_OS* MP_OS::os = NULL;

MP_OS::MP_OS(MP_Scheduler::schedule algo) {
  m_os_thread   = new MP_Thread();
  mp_scheduler  = new MP_Scheduler(algo);
  mp_dispatcher = new MP_Dispatcher(m_os_thread);
  os            = this;

  setup_intterupt_handler();
}

void MP_OS::thread_create(void (*start_routine)()) {
  MP_Thread *thread = new MP_Thread(start_routine, m_os_thread);

  m_created.push(thread);
  mp_scheduler->add_ready(thread);
}

void MP_OS::wait() {
  set_quantum();

  while( mp_scheduler->has_ready_threads() ) {
    MP_Thread *next_thread = mp_scheduler->get_next_thread();
    mp_dispatcher->execute_thread(next_thread);
  }
}

void MP_OS::setup_intterupt_handler() {
  struct sigaction act, oact;
  act.sa_handler = interrupt_handler;
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;
  sigaction(SIGALRM, &act, &oact);
}

void MP_OS::set_quantum() {
  if (mp_scheduler->needs_quantum()) {
    struct itimerval timer;

    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 50000;
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 100000;

    setitimer(ITIMER_REAL, &timer, NULL);
  }
}

void MP_OS::handle_interrupt() {
  mp_dispatcher->context_switch(mp_scheduler);
}

void MP_OS::interrupt_handler(int i) {
  os->handle_interrupt();
}

