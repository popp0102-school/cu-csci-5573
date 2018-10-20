#include <gtest/gtest.h>
#include "mp_scheduler.h"

void dummy_method2() {}

TEST(MP_Scheduler, Run) {
  MP_Thread *main_thread = new MP_Thread();
  MP_Scheduler *mp_scheduler = new MP_Scheduler(main_thread);

  EXPECT_NO_THROW(mp_scheduler->run(MP_Scheduler::ROUND_ROBIN));
};

TEST(MP_Scheduler, AddThread) {
  MP_Thread *main_thread = new MP_Thread();
  MP_Scheduler *mp_scheduler = new MP_Scheduler(main_thread);
  MP_Thread *thread_1 = new MP_Thread(dummy_method2, main_thread);
  MP_Thread *thread_2 = new MP_Thread(dummy_method2, main_thread);

  EXPECT_NO_THROW(mp_scheduler->add_thread(thread_1));
  EXPECT_NO_THROW(mp_scheduler->add_thread(thread_2));
};

