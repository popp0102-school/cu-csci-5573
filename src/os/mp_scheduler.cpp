#include "mp_scheduler.h"

MP_Scheduler::MP_Scheduler(MP_Thread *main_thread) {
  m_main_thread = main_thread;
}

void MP_Scheduler::run(schedule type) {
  if (type == FCFS) {
    round_robin();
  }
}

void MP_Scheduler::round_robin() {
  while( !m_ready_queue.empty() ) {
    MP_Thread *current_thread = m_ready_queue.front();
    m_ready_queue.pop();

    execute_thread(current_thread);
  }
}

void MP_Scheduler::add_thread(MP_Thread *mp_thread) {
  m_ready_queue.push(mp_thread);
}

void MP_Scheduler::execute_thread(MP_Thread *mp_thread) {
  swapcontext(m_main_thread->get_context(), mp_thread->get_context());
}

