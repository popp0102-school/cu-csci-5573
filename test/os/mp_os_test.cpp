#include <gtest/gtest.h>
#include "mp_os.h"

void dummy_method() {}

TEST(MP_OS, wait) {
  MP_OS *modulus_prime = new MP_OS(MP_Scheduler::FCFS);

  EXPECT_NO_THROW(modulus_prime->wait());
};

TEST(MP_OS, mpthread_create) {

  MP_OS *modulus_prime = new MP_OS(MP_Scheduler::FCFS);

  EXPECT_NO_THROW(modulus_prime->thread_create(dummy_method));
};

