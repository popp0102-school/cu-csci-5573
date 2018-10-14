#include <gtest/gtest.h>
#include "mp_scheduler.h"

TEST(MP_Scheduler, Run) {
  MP_Scheduler *mp_scheduler = new MP_Scheduler();

  EXPECT_NO_THROW(mp_scheduler->run());
};

