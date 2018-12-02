#ifndef MODULUS_PRIME_H
#define MODULUS_PRIME_H

#include "mp_os.h"
#include <string>

using namespace std;

void mp_init(MP_Scheduler::schedule, int, string);
void mp_add_thread(void (*thread_routine)(), string label);
void mp_wait();
void* mp_malloc(int);
void mp_free(void *);

#endif

