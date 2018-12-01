#ifndef MP_THREAD_H
#define MP_THREAD_H

#include <malloc.h>
#include <ucontext.h>
#include <string>
#include <iostream>
#define STACK_SIZE 1024 * 64

using namespace std;

class MP_Thread {
  public:
    enum MP_Status { RUNNING, WAITING, FINISHED };

    MP_Thread();
    MP_Thread(void (*start_routine)(), MP_Thread *main_thread, string label);

    ucontext_t* get_context();
    MP_Status get_status();
    void set_status(MP_Status);
    void swap(MP_Thread*);
    string getLabel();
    friend ostream& operator<<(ostream& os, const MP_Thread& mp_thread);

  private:
    ucontext_t m_context;
    MP_Status m_status;
    string m_label;
    int m_quantum;
};

#endif

