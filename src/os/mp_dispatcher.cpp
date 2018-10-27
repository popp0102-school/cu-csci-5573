#include "mp_dispatcher.h"
#include <iostream>

MP_Dispatcher::MP_Dispatcher(MP_Thread *os_thread) {
  m_os_thread      = os_thread;
  m_running_thread = os_thread;
}

void MP_Dispatcher::context_switch() {
  std::cout << "CONTEXT SWITCH!\n";
  execute_thread(m_os_thread);
}

void MP_Dispatcher::execute_thread(MP_Thread *on_deck_thread) {
  MP_Thread *current_running = m_running_thread;
  m_running_thread           = on_deck_thread;
  current_running->swap(on_deck_thread);
}

MP_Thread* MP_Dispatcher::get_running_thread() {
  return m_running_thread;
}

