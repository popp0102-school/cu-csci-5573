//
//  modulus-prime.cpp
//  mp_memory
//
//  Created by Natalie Plotkin on 11/12/18.
//  Copyright © 2018 Natalie Plotkin. All rights reserved.
//

#include <stdio.h>
#ifndef MODULUS_PRIME_H
#define MODULUS_PRIME_H
#include <iterator>
#include <malloc.h>
#include "mp_os.h"
#include <string>
void mp_init(MP_Scheduler::schedule, int, std::string);
void mp_add_thread(void (*thread_routine)(), std::string label);
void mp_wait();
void * mp_malloc(int);
void deallocate();

#endif
