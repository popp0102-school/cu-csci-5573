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
    MP_Dispatcher(MP_Thread*);

    void context_switch(MP_Scheduler*);
    void execute_thread(MP_Thread*);

  private:
    MP_Thread* m_os_thread;
    MP_Thread* m_running_thread;
};

#endif

