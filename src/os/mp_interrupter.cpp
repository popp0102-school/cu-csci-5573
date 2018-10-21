#include "mp_interrupter.h"
#include <iostream>

MP_Scheduler *mp_scheduler;

struct itimerval it;

void init_interrupter(MP_Scheduler *mp_sched) {
  mp_scheduler = mp_sched;

  struct sigaction act, oact;
  act.sa_handler = context_switch;
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;
  sigaction(SIGALRM, &act, &oact);

  // Start itimer
  it.it_interval.tv_sec = 1;
  it.it_interval.tv_usec = 50000;
  it.it_value.tv_sec = 1;
  it.it_value.tv_usec = 100000;
  setitimer(ITIMER_REAL, &it, NULL);
}

void run_interrupter() {
}

void context_switch(int i) {
  std::cout << "CONTEXT SWITCH!\n";
  mp_scheduler->dispatch();
}

