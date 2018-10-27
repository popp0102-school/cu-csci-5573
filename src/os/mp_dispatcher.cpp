#include "mp_dispatcher.h"
#include <iostream>

MP_Dispatcher::MP_Dispatcher(MP_Thread *os_thread) {
  m_os_thread      = os_thread;
  m_running_thread = os_thread;
}

void MP_Dispatcher::context_switch(MP_Scheduler *scheduler) {
  std::cout << "CONTEXT SWITCH!\n";

  scheduler->add_ready(m_running_thread);
  execute_thread(m_os_thread);
}

void MP_Dispatcher::execute_thread(MP_Thread *on_deck_thread) {
  MP_Thread *current_running = m_running_thread;
  m_running_thread           = on_deck_thread;
  swapcontext(current_running->get_context(), on_deck_thread->get_context());
}

