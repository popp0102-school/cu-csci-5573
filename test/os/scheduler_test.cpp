#include <gtest/gtest.h>
#include "scheduler.h"

TEST(Scheduler, Execute) {
  Scheduler *mp_scheduler = new Scheduler();

  EXPECT_NO_THROW(mp_scheduler->Execute());
};

