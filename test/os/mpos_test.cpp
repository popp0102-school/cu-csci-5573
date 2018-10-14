#include <gtest/gtest.h>
#include "mpos.h"

TEST(MPOS, Execute) {
  MPOS *modulus_prime = new MPOS();

  EXPECT_NO_THROW(modulus_prime->Execute());
};

