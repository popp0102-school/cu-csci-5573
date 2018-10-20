#ifndef MP_SCHEDULER_H
#define MP_SCHEDULER_H

#include "mp_thread.h"
#include <queue>

class MP_Scheduler {
  public:
    enum schedule { FCFS, ROUND_ROBIN };
    MP_Scheduler(MP_Thread *);
    void run(schedule);
    void add_thread(MP_Thread*);

  private:
    std::queue<MP_Thread*> m_ready_queue;
    void execute_thread(MP_Thread*);
    MP_Thread *m_main_thread;
    void round_robin();
};

#endif

