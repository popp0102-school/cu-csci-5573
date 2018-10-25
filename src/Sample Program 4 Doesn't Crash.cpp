//
//  Sample Program 4 Doesn't Crash.cpp
//  Sample Program 1
//
//  Created by Natalie Plotkin on 10/21/18.
//  Copyright © 2018 Natalie Plotkin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <sys/types.h>
#include <mp_os.h>
#include <MP_THREADS>
#include <thread>
#include "stdafx.h"
using namespace std;


//This program will crash because we do not join thread t1 to the main thread before main terminates

void threadFunction1() {
    cout << "Inside thread function 1 " << endl;
    
}
void threadFunction2(){
    cout << "Inside thread function 2 " << endl;
}


int main()
{
    
    MP_Thread t1 = new MP_Thread;
    MP_Thread t2 = new MP_Thread;
    t1.thread_create(threadFunction1);
    t2.thread_create(threadFunction2);
    t1.join();
    t2.join();
    
    return 0;
}
