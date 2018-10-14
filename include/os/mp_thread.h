#ifndef MP_THREAD_H
#define MP_THREAD_H

#include <malloc.h>
#include <ucontext.h>

#define STACK_SIZE 1024 * 64

class MP_Thread {
  private:
    ucontext_t context;

  public:
    MP_Thread(void (*start_routine)());

};

#endif

