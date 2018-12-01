#ifndef MP_SCHEDULER_H
#define MP_SCHEDULER_H

#include "mp_thread.h"
#include "mp_logger.h"
#include <queue>

using namespace std;

class MP_Scheduler {
  public:
    enum schedule { FCFS, ROUND_ROBIN, RERUN_FCFS, RERUN_ROUND_ROBIN };
    MP_Scheduler(schedule, int, string);

    void add_ready(MP_Thread*);
    bool needs_quantum();
    bool has_ready_threads();
    void RemoveThread(std::string);
    MP_Thread* get_next_thread();
    schedule get_schedule_algo();
    void clear_ready();

  private:
    std::queue<MP_Thread*> m_ready_queue;
    schedule m_algo;
    int m_quantum;
    MP_Logger *m_logger;
};

#endif

