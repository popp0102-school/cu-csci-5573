#ifndef MPOS_H
#define MPOS_H

#include "scheduler.h"

class MPOS {
  private:
    Scheduler *mp_scheduler;

  public:
    MPOS();
    void Execute();
};

#endif

