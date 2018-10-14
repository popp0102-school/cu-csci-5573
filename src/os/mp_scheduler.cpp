#include "mp_scheduler.h"

MP_Scheduler::MP_Scheduler() {
}

void MP_Scheduler::run() {

}

void MP_Scheduler::add_thread(MP_Thread *mp_thread) {
  m_ready_queue.push(mp_thread);
}

