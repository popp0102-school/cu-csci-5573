#include "mp.h"
#include <iostream>

using namespace std;

MP::MP() {
  cout << "Constructing MP\n";
  mp_scheduler = new Scheduler();

  cout << "MP complete\n";
}

void MP::Execute() {
  cout << "Executing Scheduler\n";
  mp_scheduler->Execute();
}

