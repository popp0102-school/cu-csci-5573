#include <gtest/gtest.h>
#include "mp.h"

TEST(MP, Execute) {
  MP *modulus_prime = new MP();

  EXPECT_NO_THROW(modulus_prime->Execute());
};

