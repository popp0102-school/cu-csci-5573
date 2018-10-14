#include <gtest/gtest.h>
#include "mp_scheduler.h"

void dummy_method2() {}

TEST(MP_Scheduler, Run) {
  MP_Scheduler *mp_scheduler = new MP_Scheduler();

  EXPECT_NO_THROW(mp_scheduler->run());
};

TEST(MP_Scheduler, AddThread) {
  MP_Scheduler *mp_scheduler = new MP_Scheduler();
  MP_Thread *thread_1 = new MP_Thread(dummy_method2);
  MP_Thread *thread_2 = new MP_Thread(dummy_method2);

  EXPECT_NO_THROW(mp_scheduler->add_thread(thread_1));
  EXPECT_NO_THROW(mp_scheduler->add_thread(thread_2));
};

