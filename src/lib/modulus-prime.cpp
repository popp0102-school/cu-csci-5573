#include "modulus-prime.h"

MP_OS *mp_os = NULL;

void mp_init(MP_Scheduler::schedule algo, int usecs_quantum, std::string filename) {
  mp_os = new MP_OS(algo, usecs_quantum, filename);
}

void mp_add_thread(void (*thread_routine)(), std::string label) {
  mp_os->thread_create(thread_routine, label);
}

void mp_wait() {
  mp_os->wait();
}

void* mp_malloc(int numbytes) {
  return mp_os->thread_malloc(numbytes);
}

void mp_free() {
  return mp_os->thread_free();
}

