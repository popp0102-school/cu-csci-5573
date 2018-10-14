#include <gtest/gtest.h>
#include "mp_scheduler.h"

TEST(MP_Scheduler, Execute) {
  MP_Scheduler *mp_scheduler = new MP_Scheduler();

  EXPECT_NO_THROW(mp_scheduler->Execute());
};

