#include "modulus-prime.h"
#include <iostream>

// Memory allocation and deallocation demo for a single thread
// mp_malloc - allocate and keep track of memory for the thread
// mp_free   - explicitly free this memory


void function1() {
  int* mem = (int*) mp_malloc(100000);
  mp_free(mem);
}

int main() {
  mp_init(MP_Scheduler::FCFS, 0, "demo-1.txt");
  mp_add_thread(function1,"thread-1");
  mp_wait();

  return 0;
}

