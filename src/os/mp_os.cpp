#include "mp_os.h"
#include <iostream>

using namespace std;

MP_OS::MP_OS() {
  cout << "Constructing MP_OS\n";
  mp_scheduler = new MP_Scheduler();

  cout << "MP_OS complete\n";
}

void MP_OS::Execute() {
  cout << "Executing Scheduler\n";
  mp_scheduler->Execute();
}

