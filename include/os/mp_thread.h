#ifndef MP_THREAD_H
#define MP_THREAD_H

#include <malloc.h>
#include <ucontext.h>

#define STACK_SIZE 1024 * 64

class MP_Thread {
  public:
    enum MP_Status { RUNNING, WAITING, FINISHED };

    MP_Thread();
    MP_Thread(void (*start_routine)(), MP_Thread *main_thread);
    ucontext_t* get_context();
    MP_Status get_status();
    void set_status(MP_Status);
    void swap(MP_Thread*);

  private:
    ucontext_t m_context;
    MP_Status m_status;
};

#endif

