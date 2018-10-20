#include "mp_scheduler.h"

MP_Scheduler::MP_Scheduler() {
}

void MP_Scheduler::run(MP_Thread *main_thread) {
  while( !m_ready_queue.empty() ) {
    MP_Thread *current_thread = m_ready_queue.front();
    m_ready_queue.pop();

    swapcontext(main_thread->get_context(), current_thread->get_context());
  }
}

void MP_Scheduler::add_thread(MP_Thread *mp_thread) {
  m_ready_queue.push(mp_thread);
}

