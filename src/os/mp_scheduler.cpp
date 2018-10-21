#include "mp_scheduler.h"
#include <iostream>

MP_Scheduler::MP_Scheduler(MP_Thread *main_thread, schedule algo) {
  m_algo           = algo;
  m_main_thread    = main_thread;
  m_running_thread = main_thread;
}

void MP_Scheduler::run() {
  if (m_algo == FCFS) {
    fcfs();
  } else if( m_algo == ROUND_ROBIN ) {
    round_robin();
  }
}

void MP_Scheduler::round_robin() {

}

void MP_Scheduler::fcfs() {
  while( !m_ready_queue.empty() ) {
    MP_Thread *next_thread = m_ready_queue.front();
    m_ready_queue.pop();
    std::cout << "POP POP\n";

    execute_thread(next_thread);
  }
}

void MP_Scheduler::dispatch() {
    std::cout << "DISPATCH\n";
  execute_thread(m_main_thread);
}

void MP_Scheduler::add_thread(MP_Thread *mp_thread) {
  m_ready_queue.push(mp_thread);
}

void MP_Scheduler::execute_thread(MP_Thread *on_deck_thread) {
  MP_Thread *current_running = m_running_thread;
  m_running_thread = on_deck_thread;
  swapcontext(current_running->get_context(), on_deck_thread->get_context());
}

