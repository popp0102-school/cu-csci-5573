#ifndef MP_DISPATCHER_H
#define MP_DISPATCHER_H

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/time.h>
#include "mp_scheduler.h"

void init_dispatcher(MP_Scheduler *);
void run_dispatcher();
void context_switch(int i);

#endif

