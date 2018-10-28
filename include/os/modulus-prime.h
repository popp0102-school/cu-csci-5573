#ifndef MODULUS_PRIME_H
#define MODULUS_PRIME_H

#include "mp_os.h"

class ModulusPrime {
  public:
    static void init(MP_Scheduler::schedule, int);
    static void add_thread(void (*thread_routine)());
    static void wait();

  private:
    static MP_OS *mp_os;
};

#endif



