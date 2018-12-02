#include "modulus-prime.h"
#include <iostream>

void function1() {
  int count = 0;
  while(1) {
    count++;
    if (count % 100000000 == 0 ) {
      std::cout << "function 1 here\n";
    }
  }
}

void function2() {
  int count = 0;
  while(1) {
    count++;
    if (count % 100000000 == 0 ) {
      std::cout << "function 2 here\n";
    }
  }
}

int main() {
  mp_init(MP_Scheduler::RERUN, 900000, "replay.txt");
  mp_add_thread(function1, "thread1");
  mp_add_thread(function2, "thread2");
  mp_wait();

  return 0;
}

