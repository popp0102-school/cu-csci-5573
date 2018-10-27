#include "mp_scheduler.h"
#include <iostream>

MP_Scheduler::MP_Scheduler(schedule algo) {
  m_algo = algo;
}

bool MP_Scheduler::has_ready_threads() {
  if( m_ready_queue.empty() ) {
    return false;
  }

  return true;
}

MP_Thread* MP_Scheduler::get_next_thread() {
  MP_Thread* next_thread = NULL;

  if( has_ready_threads() ) {
    next_thread = m_ready_queue.front();
    m_ready_queue.pop();
  }

  return next_thread;
}


bool MP_Scheduler::needs_quantum() {
 if( m_algo == ROUND_ROBIN ) {
   return true;
 }

 return false;
}

void MP_Scheduler::add_ready(MP_Thread *mp_thread) {
  m_ready_queue.push(mp_thread);
}


