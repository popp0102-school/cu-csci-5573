#include "mp_os.h"

MP_OS::MP_OS(MP_Scheduler::schedule algo) {
  m_os_thread  = new MP_Thread();
  mp_scheduler = new MP_Scheduler(m_os_thread, algo);

  init_dispatcher(mp_scheduler);
}

void MP_OS::thread_create(void (*start_routine)()) {
  MP_Thread *thread = new MP_Thread(start_routine, m_os_thread);

  m_created.push(thread);
  mp_scheduler->add_ready(thread);
}

void MP_OS::run() {
  run_dispatcher();

  mp_scheduler->run();
}

