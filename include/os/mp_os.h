#ifndef MP_OS_H
#define MP_OS_H

#include "mp_scheduler.h"

class MP_OS {
  private:
    MP_Scheduler *mp_scheduler;

  public:
    MP_OS();
    void run();
    void thread_create(void (*start_routine)());
};

#endif

