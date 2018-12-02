#ifndef MP_OS_H
#define MP_OS_H

#include <queue>
#include <sys/time.h>

#include "mp_scheduler.h"
#include "mp_dispatcher.h"
#include "mp_thread.h"
#include "mp_memory_manager.h"
#include "mp_logger.h"
#include "memorydumper.h"
#include "mpStackTrace.h"

using namespace std;

class MP_OS {
  public:
    MP_OS(MP_Scheduler::schedule, int, string);

    void thread_create(void (*start_routine)(), string label);
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

    // Premption / Context Switching
    void start_quantum_timer(int);
    void stop_quantum_timer();
    void set_quantum_timer(int);
    void quantum_expired();

    // Cleanup / Garbage Collection
    void handle_finished_threads(MP_Thread*);

    // Recovery Handling
    void log_stacktrace();
    void segfault_recovery();

    // Interrupt Handling
    void setup_interrupt_handlers();
    void setup_context_switch_interrupt_handler();

    static MP_OS* os;
    static void context_switch_interrupt_handler(int i);
    static void exception_handlers(int);
};

#endif

