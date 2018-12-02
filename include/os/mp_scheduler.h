#ifndef MP_SCHEDULER_H
#define MP_SCHEDULER_H

#include "mp_thread.h"
#include "mp_logger.h"
#include <sstream>
#include <string.h>
#include <fstream>
#include <queue>
#include <map>

using namespace std;

class MP_Scheduler {
  public:
    enum schedule { FCFS, ROUND_ROBIN, RERUN_FCFS, RERUN_ROUND_ROBIN, RERUN };
    MP_Scheduler(schedule, int, string);

    void add_ready(MP_Thread*);
    bool has_ready_threads();
    void clear_thread(string);
    MP_Thread* get_next_thread();

  private:
    schedule m_algo;
    queue<MP_Thread*> m_ready_queue;
    queue<string> rerun_queue;
    map <string, MP_Thread*> m_thread_map;
    MP_Logger *m_logger;
    int m_quantum;

    void reschedule();
};

#endif

