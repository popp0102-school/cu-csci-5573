#include "modulus-prime.h"
#include <iostream>
#include <unistd.h>

// Demo 5 - Segfault Crash
//
// Because of the order dependency of the way this was implemented
// we will get a segfault if thread 2 is run before thread 1

class Dummy {
  public:
  string dummyName;
};

Dummy *dummy1 = NULL;

void function1(){
  dummy1 = new Dummy();
  cout << "function 1 executing, dummy object, dummy1 instantiated" <<  endl;
}

void function2(){
  dummy1->dummyName = "BIG DUMMY!";
  cout << "function 2 executing, dummy1 named " << dummy1->dummyName << endl;
}

int main() {
  mp_init(MP_Scheduler::FCFS, 500000, "demo-5.txt");
  mp_add_thread(function2,"thread2");
  mp_add_thread(function1,"thread1");
  mp_wait();

  return 0;
}

