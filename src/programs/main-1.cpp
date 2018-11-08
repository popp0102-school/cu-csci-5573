#include "modulus-prime.h"
#include <iostream>

void function1() {
  std::cout << "function 1 here\n";
}

void function2() {
  std::cout << "function 2 here\n";
}

int main() {
  mp_init(MP_Scheduler::FCFS, 0, "main-1LOG.txt");
  mp_add_thread(function1,"main-1-1");
  mp_add_thread(function2,"main-1-2");
  mp_wait();

  return 0;
}

