#include "mp_dispatcher.h"
#include <iostream>

MP_Dispatcher* MP_Dispatcher::dispatcher = NULL;

MP_Dispatcher::MP_Dispatcher(MP_Scheduler *mp_sched) {
  my_scheduler = mp_sched;

  // set up context switch handler
  struct sigaction act, oact;
  act.sa_handler = context_switch;
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;
  sigaction(SIGALRM, &act, &oact);

  dispatcher = this;
}

void MP_Dispatcher::set_quantum() {
  if (my_scheduler->needs_quantum()) {
    init_timer();
    setitimer(ITIMER_REAL, &it, NULL);
  }
}

void MP_Dispatcher::context_switch(int i) {
  std::cout << "CONTEXT SWITCH!\n";
  dispatcher->my_scheduler->dispatch();
}

void MP_Dispatcher::init_timer() {
  it.it_interval.tv_sec = 1;
  it.it_interval.tv_usec = 50000;
  it.it_value.tv_sec = 1;
  it.it_value.tv_usec = 100000;
}
