#include "mp_os.h"


MP_OS::MP_OS() {
  mp_scheduler = new MP_Scheduler();

}

void MP_OS::thread_create(void (*start_routine)()) {
  MP_Thread *thread = new MP_Thread(start_routine);
  mp_scheduler->add_thread(thread);
}

void MP_OS::run() {
}

