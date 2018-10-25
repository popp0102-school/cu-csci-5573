//
//  Sample Program 2.cpp
//  Sample Program 1
//
//  Created by Natalie Plotkin on 10/20/18.
//  Copyright © 2018 Natalie Plotkin. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <sys/types.h>
//#include <mp_os.h>
#include <thread>
#include <mp_os.h>
#include <MP_THREADS>

#include "stdafx.h"
#include <POSIX>
using namespace std;

int x = 5;

// show that something can never get to where it needs to go with cout
// thread_create

void threadFunction1() {
    while(x > 0)
    {
    
        cout << " Thread is inside function 1 where the goal is for x to count from 5 down to 0, x  = " << x << endl;
       
        if( x == 0){
        cout << "x got to 0! time to end the program" << endl;
        terminate();
        }
        else
        {
            cout << "x still not at 0"  << endl;
        }
        x--;
        
    }
}

void threadFunction2(){
    
    while(x <= 10)
    {
      
        cout << "Thread is inside function 2 where the goal is for x to count up from 5 to 10, x = " << x << endl;
        
        if(x==10){
            cout << "x got to 10! time to terminate the program" << endl;
            terminate();
        }
        else
        {
            cout << "x not still not at 10" << endl;
        }
            
        x++;
    }
    
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

