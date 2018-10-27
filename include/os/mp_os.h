#ifndef MP_OS_H
#define MP_OS_H

#include "mp_scheduler.h"
#include "mp_dispatcher.h"
#include "mp_thread.h"
#include <queue>

class MP_OS {
  public:
    MP_OS(MP_Scheduler::schedule);

    void thread_create(void (*start_routine)());
    void wait();

  private:
    MP_Dispatcher *m_dispatcher;
    MP_Scheduler *m_scheduler;
    MP_Thread *m_os_thread;

    void setup_intterupt_handler();
    void set_quantum();
    void handle_interrupt();

    static MP_OS* os;
    static void interrupt_handler(int i);
};

#endif

