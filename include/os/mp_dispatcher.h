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
    static void interrupt_handler(int i);

    MP_Dispatcher(MP_Scheduler*, MP_Thread*);
    void run();
    void context_switch();

  private:
    static MP_Dispatcher* dispatcher;

    MP_Thread* m_os_thread;
    MP_Thread* m_running_thread;
    MP_Scheduler *m_scheduler;

    void setup_intterupt_handler();
    void set_quantum();

    void execute_thread(MP_Thread *on_deck_thread);
};

#endif

