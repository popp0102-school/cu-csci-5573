#ifndef MP_OS_H
#define MP_OS_H

#include <queue>
#include <sys/time.h>
#include<exception>
#include "mp_scheduler.h"
#include "mp_dispatcher.h"
#include "mp_thread.h"
#include "mp_memory_manager.h"
#include "mp_logger.h"
#include <string>
#include "memorydumper.h"
#include "mpStackTrace.h"
#include <sstream>
#include <fstream>
class MP_OS {
  public:
    MP_OS(MP_Scheduler::schedule, int, std::string);

    void thread_create(void (*start_routine)(), std::string label);
    void wait();
    void* mp_malloc(int numbytes);
    void mp_free(void *mem);

  private:
    MP_Logger *m_logger;
    MP_Dispatcher *m_dispatcher;
    MP_Scheduler *m_scheduler;
    MP_Thread *m_os_thread;
    MP_MemoryManager *m_memory_manager;
    bool m_quantum_exp;
    struct itimerval m_quantum_timer;
    std::queue<MP_Thread*> m_user_threads;
    void setup_interrupt_handlers();
    void setup_context_switch_interrupt_handler();
    void start_quantum_timer(int);
    void stop_quantum_timer();
    void set_quantum_timer(int);
    void quantum_expired();
    void handle_finished_threads(MP_Thread::MP_Status, MP_Thread*);
    void log_stacktrace();
    void segfault_recovery();
    void ReSchedule();

    static MP_OS* os;
    static void context_switch_interrupt_handler(int i);
    static void exception_handlers(int);
};

#endif

