#include "modulus-prime.h"
#include <queue>
#include <iostream>
#include <unistd.h>

// Demo 6 - Bounded Buffer
//
// Ordinary Producer Consumer using mp-threads

queue<string> buffer;

void Producer(){
  int value = 0;

  while(1) {
    sleep(1000);
    value = rand() % 100;
    cout << "\nQueue Size: " << buffer.size() << endl;
    cout << "Producing value: " << value << endl;
    buffer.push(to_string(value));
  }
}

void Consumer(){
  while(1) {
    if(!buffer.empty()) {
      string element = buffer.front();
      buffer.pop();
      cout << "Consuming element: " << element << endl << endl;
    } else {
      cout << "Taking a nap not much to do\n";
      sleep(100);
    }
  }
}

int main() {
  mp_init(MP_Scheduler::ROUND_ROBIN, 500000, "demo-6.txt");

  mp_add_thread(Producer, "producer1");
  mp_add_thread(Producer, "producer2");
  mp_add_thread(Producer, "producer3");
  mp_add_thread(Producer, "producer4");
  mp_add_thread(Producer, "producer5");
  mp_add_thread(Consumer, "consumer");
  mp_wait();

  return 0;
}

