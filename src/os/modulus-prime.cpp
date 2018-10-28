#include "modulus-prime.h"

MP_OS* ModulusPrime::mp_os = NULL;

void ModulusPrime::init(MP_Scheduler::schedule algo, int usecs_quantum) {
  mp_os = new MP_OS(algo, usecs_quantum);
}

void ModulusPrime::add_thread(void (*thread_routine)()) {
  mp_os->thread_create(thread_routine);
}

void ModulusPrime::wait() {
  mp_os->wait();
}

