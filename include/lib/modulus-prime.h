#ifndef MODULUS_PRIME_H
#define MODULUS_PRIME_H

#include "mp_os.h"
#include <string>

void mp_init(MP_Scheduler::schedule, int, std::string);
void mp_add_thread(void (*thread_routine)(), std::string label);
void mp_wait();
void* thread_malloc(int);

#endif

