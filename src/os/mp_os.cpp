#include "mp_os.h"


MP_OS::MP_OS() {
  mp_scheduler = new MP_Scheduler();
  m_main_thread = new MP_Thread();
}

void MP_OS::thread_create(void (*start_routine)()) {
  MP_Thread *thread = new MP_Thread(start_routine, m_main_thread);
  mp_scheduler->add_thread(thread);
}

void MP_OS::run() {
  mp_scheduler->run();
}

