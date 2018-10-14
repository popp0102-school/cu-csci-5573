#include "mpos.h"
#include <iostream>

using namespace std;

MPOS::MPOS() {
  cout << "Constructing MPOS\n";
  mp_scheduler = new Scheduler();

  cout << "MPOS complete\n";
}

void MPOS::Execute() {
  cout << "Executing Scheduler\n";
  mp_scheduler->Execute();
}

