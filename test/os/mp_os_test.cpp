#include <gtest/gtest.h>
#include "mp_os.h"

TEST(MP_OS, run) {
  MP_OS *modulus_prime = new MP_OS();

  EXPECT_NO_THROW(modulus_prime->run());
};

TEST(MP_OS, mpthread_create) {
  MP_OS *modulus_prime = new MP_OS();

  EXPECT_NO_THROW(modulus_prime->mpthread_create());
};

