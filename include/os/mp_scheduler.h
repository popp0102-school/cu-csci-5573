#ifndef MP_SCHEDULER_H
#define MP_SCHEDULER_H

#include "mp_thread.h"
#include <queue>

class MP_Scheduler {
  private:
    std::queue<MP_Thread*> m_ready_queue;

  public:
    MP_Scheduler();
    void run(MP_Thread *);
    void add_thread(MP_Thread*);
};

#endif

