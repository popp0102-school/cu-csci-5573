#ifndef MP_OS_H
#define MP_OS_H

#include "mp_scheduler.h"
#include "mp_thread.h"

class MP_OS {
  private:
    MP_Scheduler *mp_scheduler;
    MP_Thread *m_main_thread;

  public:
    MP_OS(MP_Scheduler::schedule);
    void run();
    void thread_create(void (*start_routine)());
};

#endif

