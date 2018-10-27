#ifndef MP_THREAD_H
#define MP_THREAD_H

#include <malloc.h>
#include <ucontext.h>

#define STACK_SIZE 1024 * 64

class MP_Thread {
  public:
    MP_Thread();
    MP_Thread(void (*start_routine)(), MP_Thread *main_thread);
    ucontext_t* get_context();

  private:
    ucontext_t m_context;

};

#endif

