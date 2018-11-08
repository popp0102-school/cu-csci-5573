//
//  Sample Program 2.cpp
//  Sample Program 1
//
//  Created by Natalie Plotkin on 10/20/18.
//  Copyright © 2018 Natalie Plotkin. All rights reserved.
//
#include "modulus-prime.h"
#include <iostream>
using namespace std;


int x = 100000;

// show that something can never get to where it needs to go with cout
// thread_create

void function1() {	
	int count = 0;	
//	while(x >=0)i
        while(1)
     {  
	count++;     
    	if(count % 100000000 == 0){
        	cout << " Thread is inside function 1 where the goal is for x to count from 100000 down to 0, x  = " << x << endl;
       
        		if( x == 0){
            		cout << "x got to 0! time to end the program" << endl;
       			 terminate();
        		}
       			 else
        		{
          	        cout << "x still not at 0"  <<endl;
       			}
		x--;
	} 
      //  x--;
        
    }
}

void function2(){
    
    int count = 0;   	
   // while(x <= 10)
      while(1)
    { 
      count++;
      if(count % 100000000 ==0){
        cout << "Thread is inside function 2 where the goal is for x to count up from 10000 to 1000000000, x = " << x << endl;
        
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
       // x++;
    }
    
}


int main()
{
    
    /* mp_init(MP_Scheduler::FCFS, 0);
     mp_add_thread(function1);
     mp_add_thread(function2);
     mp_wait();
     */
    mp_init(MP_Scheduler::ROUND_ROBIN,900000);

    mp_add_thread(function1, "A");
    mp_add_thread(function2, "B");
    mp_wait();
   // MP_Thread t1 = new MP_Thread;
   // MP_Thread t2 = new MP_Thread;
    
  //  t1.thread_create(threadFunction1);
    //t2.thread_create(threadFunction2);
//    t1.join();
   // t2.join();
    return 0;
}

