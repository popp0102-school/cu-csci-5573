#include "mp_os.h"
#include <iostream>

void function1() {
  std::cout << "function 1 here\n";
}

void function2() {
  std::cout << "function 2 here\n";
}

int main() {
  MP_OS *modulus_prime = new MP_OS();
  modulus_prime->run();

  function1();
  function2();

  return 0;
}

