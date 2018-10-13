#include <gtest/gtest.h>
#include "scheduler.h"

TEST(BasicTest, Equality) {
  ASSERT_EQ(0, 0);
};

TEST(Scheduler, Basic) {
  Scheduler *mp_scheduler = new Scheduler();

  EXPECT_NO_THROW(mp_scheduler->Execute());
};

