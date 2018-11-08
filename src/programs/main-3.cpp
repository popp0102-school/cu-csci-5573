//  Sample Program 1
// by Natalie Plotkin on 10/20/18.
//  Copyright © 2018 Natalie Plotkin. All rights reserved.
//

#include "modulus-prime.h"
#include <iostream>
using namespace std;

/*In this program, there is a common resource between the threads and thread 1 must initialize it before the other can use it, but if the one that tried to initializ it doesnt run yet then the other thread should crash*/

// create some dummy class
class Dummy {
    public:
    string dummyName;
    
};

Dummy *dummy1 = NULL;

void function1(){
     // instantiate dummy object with new
     dummy1 = new Dummy();
    cout << "function 1 executing, dummy object, dummy1 instantiated" <<  endl; 
}

void function2(){
    // set an attribute on the dummy object
    dummy1->dummyName = "BIG DUMMY!";
   cout << "function 2 executing, dummy1 named " << dummy1->dummyName << endl;
}




int main(){
    mp_init(MP_Scheduler::FCFS, 0, "main-3LOG.txt");
    mp_add_thread(function2, "main-3-2");
    mp_add_thread(function1, "main-3-1");
    mp_wait();


    
    return(0);
}

