#include "modulus-prime.h"
#include <iostream>
/*
void function1() {
  std::cout << "function 1 here\n";
}

void function2() {
  std::cout << "function 2 here\n";
}

int main() {
  mp_init(MP_Scheduler::RERUN_FCFS, 0, "main-1LOG.txt");
  mp_add_thread(function1,"main-1-1");
  mp_add_thread(function2,"main-1-2");
  mp_wait();

  return 0;
}
*/


void function3() {
  int count = 0;
  while(1) {
    count++;
    if (count % 100000000 == 0 ) {
      std::cout << "function 3 here\n";
    }
  }
}

void function4() {
  int count = 0;
  while(1) {
    count++;
    if (count % 100000000 == 0 ) {
      std::cout << "function 4 here\n";
    }
  }
}

int main() {
  mp_init(MP_Scheduler::RERUN_ROUND_ROBIN, 900000, "main-2LOG.txt");
  mp_add_thread(function3, "main-2-3");
  mp_add_thread(function4, "main-2-4");
  mp_wait();

  return 0;
}

