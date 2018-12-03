#include "modulus-prime.h"
#include <iostream>
#include <unistd.h>

// Scheduling ROUND ROBIN

void function1() {
  int count = 0;
  while(1) {
    count++;
    if (count % 100000000 == 0 ) {
      std::cout << "Thread 1 is executing\n";
    }
  }
}

void function2() {
  int count = 0;
  while(1) {
    count++;
    if (count % 100000000 == 0 ) {
      std::cout << "Thread 2 is executing\n";
    }
  }
}

int main() {
  mp_init(MP_Scheduler::ROUND_ROBIN, 500000, "demo-2.txt");
  mp_add_thread(function1,"thread-1");
  mp_add_thread(function2,"thread-2");
  mp_wait();

  return 0;
}

