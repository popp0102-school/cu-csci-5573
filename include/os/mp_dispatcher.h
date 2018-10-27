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
    static void interrupt(int i);
    void context_switch();

    MP_Dispatcher(MP_Scheduler*, MP_Thread*);
    void set_quantum();
    void run();

  private:
    MP_Thread* m_os_thread;
    MP_Thread* m_running_thread;
    MP_Scheduler *m_scheduler;

    static MP_Dispatcher* dispatcher;
    struct itimerval it;

    void init_timer();
    void init_context_switch_handler();

    void execute_thread(MP_Thread *on_deck_thread);
};

#endif

