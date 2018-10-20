#ifndef MP_SCHEDULER_H
#define MP_SCHEDULER_H

#include "mp_thread.h"
#include <queue>

class MP_Scheduler {
  private:
    std::queue<MP_Thread*> m_ready_queue;
    void execute_thread(MP_Thread*);
    MP_Thread *m_main_thread;

  public:
    MP_Scheduler(MP_Thread *);
    void run();
    void add_thread(MP_Thread*);
};

#endif

