#ifndef MP_H
#define MP_H

#include "scheduler.h"

class MP {
  private:
    Scheduler *mp_scheduler;

  public:
    MP();
    void Execute();
};

#endif

