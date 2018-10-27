#ifndef MP_DISPATCHER_H
#define MP_DISPATCHER_H

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/time.h>
#include "mp_scheduler.h"

class MP_Dispatcher {
  public:
    static void context_switch(int i);

    MP_Dispatcher(MP_Scheduler *);
    void set_quantum();


  private:
    static MP_Dispatcher* dispatcher;

    MP_Scheduler *my_scheduler;
    struct itimerval it;
};

#endif

