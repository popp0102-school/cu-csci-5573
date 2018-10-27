#ifndef MP_DISPATCHER_H
#define MP_DISPATCHER_H

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/time.h>
#include "mp_scheduler.h"
#include "mp_thread.h"

class MP_Dispatcher {
  public:
    static void context_switch(int i);

    MP_Dispatcher(MP_Scheduler*, MP_Thread*);
    void set_quantum();


  private:
    MP_Thread* m_os_thread;

    static MP_Dispatcher* dispatcher;
    MP_Scheduler *my_scheduler;
    struct itimerval it;

    void init_timer();
    void init_context_switch_handler();
};

#endif

