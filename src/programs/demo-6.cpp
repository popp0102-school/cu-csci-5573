#include "modulus-prime.h"
#include <iostream>
#include <unistd.h>

// Demo 6 - Segfault Crash
//
// Because of the order dependency of the way this was implemented
// we will get a segfault if thread 2 is run before thread 1

class Dummy {
  public:
  string dummyName;
};

Dummy *dummy1 = NULL;

void function1(){
  cout << "Thread 1 is creating a Dummy Object\n";
  dummy1 = new Dummy();

  // do some other stuff - long enough to cause a context switch
  int count = 0;
  while(1) {
    count++;
    if (count % 1000000 == 0 ) {
      break;
    }
  }

  dummy1->dummyName = "BIG DUMMY!";
  cout << "Thread1 is asking the dummy objects name: " << dummy1->dummyName << endl;
}

void function2(){
  dummy1 = NULL;
  cout << "Thread2 is squashing dummy\n";
}

int main() {
  mp_init(MP_Scheduler::RERUN, 500, "demo-6.txt");
  mp_add_thread(function1,"thread1");
  mp_add_thread(function2,"thread2");
  mp_wait();

  return 0;
}

