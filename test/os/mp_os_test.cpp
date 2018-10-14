#include <gtest/gtest.h>
#include "mp_os.h"

TEST(MP_OS, Execute) {
  MP_OS *modulus_prime = new MP_OS();

  EXPECT_NO_THROW(modulus_prime->Execute());
};

