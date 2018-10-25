//
//  Sample Program 3.cpp
//  Sample Program 1
//
//  Created by Natalie Plotkin on 10/20/18.
//  Copyright © 2018 Natalie Plotkin. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <sys/types.h>
//#include <mp_os.h>
#include <thread>
#include <mp_os.h>
#include <MP_THREADS>

#include "stdafx.h"
#include <POSIX>
#include <pthread.h>

/*In this program, there is a common resource between the threads and thread 1 must initialize it before the other can use it, but if the one that tried to initializ it doesnt run yet then the other thread should crash*/


using namespace std;
int x;

// create some dummy class
class Dummy {
    public:
    string dummyName;
    
    void printName()
    {
        cout << "dummyName is " << dummyName << endl;
        
    }
    void printStatus()
    {
        cout << "new dummy object, dummy1, instantiated in thread function 1" << endl;
    }
};


void threadFunction1(){
    // instantiate dummy object with new
    Dummy dummy1 = *new Dummy;
    printStatus();
    
}

void threadFunction2(){
    // set an attribute on the dummy object
    dummy1.dummyName = "Natalie";
    dummy1.printName();
}

int main(){
        
    MP_Thread t1 = new MP_Thread;
    MP_Thread t2 = new MP_Thread;

    t1.thread_create(threadFunction1);
    t2.thread_create(threadFunction2);


    t1.join();
    t2.join();
    
    return(0);
}

