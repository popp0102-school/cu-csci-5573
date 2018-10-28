#include "modulus-prime.h"
#include <iostream>

void function1() {
  std::cout << "function 1 here\n";
}

void function2() {
  std::cout << "function 2 here\n";
}

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
  mp_init(MP_Scheduler::ROUND_ROBIN, 900000);
  mp_add_thread(function3);
  mp_add_thread(function4);
  mp_wait();

  return 0;
}

