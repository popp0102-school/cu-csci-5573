//
//  main.cpp
//  mp_memory
//
//  Created by Natalie Plotkin on 11/8/18.
//  Copyright © 2018 Natalie Plotkin. All rights reserved.

#include "mp_scheduler.h"
#include "mp_dispatcher.h"
#include "MP_Logger.h"
#include "MP_Thread.h"
#include <iterator>
#include <malloc.h>
#include <ucontext.h>
#include <string>
#include <map>
#include mp_MemMan.h
#include <iostream>
using namespace std;

//HashMap


MP_MemMan::MemMan(){
    
}

MP_MemMan::~MemMan(){
    
}


void * mp_malloc(int numbytes, MP_Thread *mp_thread){
    void * mem = malloc(numbytes);
    mp_memory_map.insert(std::pair<std::string, void*> (mp_thread->getLabel(), numbytes));
    return mem;
}

//check the void MP_OS::handle_finished_threads() function

void deallocate(MP_Thread *mp_thread){

    free(mp_memory_map[mp_thread->getLabel()]);
    
}






