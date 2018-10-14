#include "mp_thread.h"

MP_Thread::MP_Thread(void (*start_routine)()) {
  getcontext(&context);

  context.uc_link           = NULL;
  context.uc_stack.ss_sp    = malloc(STACK_SIZE);
  context.uc_stack.ss_size  = STACK_SIZE;
  context.uc_stack.ss_flags = 0;

  makecontext(&context, start_routine, 0);
}

