//
//  modulus-prime.cpp
//  mp_memory
//
//  Created by Natalie Plotkin on 11/12/18.
//  Copyright © 2018 Natalie Plotkin. All rights reserved.
//

#include "modulus-prime.hpp"
#include "modulus-prime.h"

MP_OS *mp_os = NULL;

void mp_init(MP_Scheduler::schedule algo, int usecs_quantum, std::string label) {
    mp_os = new MP_OS(algo, usecs_quantum, label);
}

void mp_add_thread(void (*thread_routine)(), std::string label) {
    mp_os->thread_create(thread_routine, label);
}

void mp_wait() {
    mp_os->wait();
}

void * mp_malloc(int numbytes){
    mp_os-> mp_malloc(numbytes);
    
}


/*dont forget to add mp_malloc(numbytes); call in the function of the thread*/
/*also need to pull mp_os.cpp and implement the allocate and in mo_os inside wait() do the other thing*/




