#include "mp_thread.h"

MP_Thread::MP_Thread() {
  getcontext(&m_context);

  m_status  = WAITING;
  m_label   = "default";
  m_quantum = -1;
}

MP_Thread::MP_Thread(void (*start_routine)(), MP_Thread *main_thread, string label) {
  getcontext(&m_context);

  m_context.uc_link           = main_thread->get_context();
  m_context.uc_stack.ss_sp    = malloc(STACK_SIZE);
  m_context.uc_stack.ss_size  = STACK_SIZE;
  m_context.uc_stack.ss_flags = 0;
  m_label                     = label;
  m_quantum                   = -1;

  makecontext(&m_context, start_routine, 0);
}

void MP_Thread::set_quantum(int quantum) {
  m_quantum = quantum;
}

int MP_Thread::get_quantum() {
  return m_quantum;
}

ucontext_t* MP_Thread::get_context() {
  return &m_context;
}

MP_Thread::MP_Status MP_Thread::get_status() {
  return m_status;
}

void MP_Thread::set_status(MP_Status status) {
  m_status = status;
}

void MP_Thread::swap(MP_Thread* next_thread) {
  swapcontext(this->get_context(), next_thread->get_context());
}

string MP_Thread::getLabel() {
  return m_label;
}
ostream& operator<<(ostream& os, const MP_Thread& mp_thread){
  os << mp_thread.m_label << "," << mp_thread.m_quantum << endl;
  return os;
}

