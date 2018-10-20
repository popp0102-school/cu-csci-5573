#include "mp_os.h"
#include <iostream>

void function1() {
  std::cout << "function 1 here\n";
}

void function2() {
  std::cout << "function 2 here\n";
}

int main() {
  MP_OS *mpos = new MP_OS(MP_Scheduler::FCFS);

  mpos->thread_create(function1);
  mpos->thread_create(function2);

  mpos->run();

  return 0;
}

