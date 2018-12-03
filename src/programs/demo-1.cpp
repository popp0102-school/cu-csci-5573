#include "modulus-prime.h"
#include <iostream>
#include <unistd.h>

// Scheduling FCFS

void function1() {
  sleep(2000);
  std::cout << "FUNCTION 1!!!\n";
}

void function2() {
  std::cout << "FUNCTION 2!!!\n";
}

int main() {
  mp_init(MP_Scheduler::FCFS, -1, "demo-1.txt");
  mp_add_thread(function1,"thread-1");
  mp_add_thread(function2,"thread-2");
  mp_wait();

  return 0;
}

