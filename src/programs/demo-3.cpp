#include "modulus-prime.h"
#include <iostream>
#include <unistd.h>

// Memory allocation and deallocation demo for a single thread
// mp_malloc - allocate and keep track of memory for the thread
// mp_free   - explicitly free this memory


void function1() {
  cout << "Allocating memory\n";
  sleep(5);

  int* mem = (int*) mp_malloc(1000000000);
  cout << "Finished allocating memory\n";

  sleep(5);
  cout << "Freeing Memory\n";

  mp_free(mem);
  sleep(5);

  cout << "Memory Freed\n";
}

int main() {
  mp_init(MP_Scheduler::FCFS, 0, "demo-3.txt");
  mp_add_thread(function1,"thread-1");
  mp_wait();

  return 0;
}

