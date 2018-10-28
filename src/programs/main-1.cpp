#include "modulus-prime.h"
#include <iostream>

void function1() {
  std::cout << "function 1 here\n";
}

void function2() {
  std::cout << "function 2 here\n";
}

int main() {
  mp_init(MP_Scheduler::FCFS, 0);
  mp_add_thread(function1);
  mp_add_thread(function2);
  mp_wait();

  return 0;
}

