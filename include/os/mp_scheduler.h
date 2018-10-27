#ifndef MP_SCHEDULER_H
#define MP_SCHEDULER_H

#include "mp_thread.h"
#include <queue>

class MP_Scheduler {
  public:
    enum schedule { FCFS, ROUND_ROBIN };
    MP_Scheduler(schedule);

    void add_ready(MP_Thread*);
    bool needs_quantum();
    bool has_ready_threads();
    MP_Thread* get_next_thread();

  private:
    std::queue<MP_Thread*> m_ready_queue;
    schedule m_algo;
};

#endif

