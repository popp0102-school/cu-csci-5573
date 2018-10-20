#include "mp_thread.h"


MP_Thread::MP_Thread() {
  getcontext(&m_context);
}


MP_Thread::MP_Thread(void (*start_routine)()) {
  getcontext(&m_context);

  m_context.uc_link           = NULL;
  m_context.uc_stack.ss_sp    = malloc(STACK_SIZE);
  m_context.uc_stack.ss_size  = STACK_SIZE;
  m_context.uc_stack.ss_flags = 0;

  makecontext(&m_context, start_routine, 0);
}

