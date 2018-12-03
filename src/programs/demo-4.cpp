#include "modulus-prime.h"
#include <iostream>
#include <unistd.h>


// Garbage Collection
// mp_malloc - allocate and keep track of memory for the thread
// mp_free   - is not needed
//
// watch -n 0.1 "ps aux | grep bin/demo-2"


void function1() {
  // Allow enough time to see current memory
  sleep(5000);

  // Allocate a bunch of memory
  int* mem1 = (int*) mp_malloc(10000000);
  int* mem2 = (int*) mp_malloc(10000000);
  int* mem3 = (int*) mp_malloc(10000000);
  int* mem4 = (int*) mp_malloc(10000000);
  int* mem5 = (int*) mp_malloc(10000000);

  sleep(2000);

  *mem1 = 1000;
  *mem2 = 1000;
  *mem3 = 1000;
  *mem4 = 1000;
  *mem5 = 1000;

  // Memory garbage collected automatically
}

void function2() {
  int count = 0;
  while(1) {
    count++;
    if (count % 100000000 == 0 ) {
      std::cout << "function 2 running here\n";
    }
  }
}

int main() {
  mp_init(MP_Scheduler::ROUND_ROBIN, 900000, "demo-4.txt");
  mp_add_thread(function1,"thread-1");
  mp_add_thread(function2,"thread-2");
  mp_wait();

  return 0;
}

