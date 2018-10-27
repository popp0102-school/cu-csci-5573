#ifndef MP_DISPATCHER_H
#define MP_DISPATCHER_H

#include "mp_thread.h"

class MP_Dispatcher {
  public:
    MP_Dispatcher(MP_Thread*);

    void context_switch();
    void execute_thread(MP_Thread*);
    MP_Thread* get_running_thread();

  private:
    MP_Thread* m_os_thread;
    MP_Thread* m_running_thread;
};

#endif

