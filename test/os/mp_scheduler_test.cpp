#include <gtest/gtest.h>
#include "mp_scheduler.h"

void dummy_method2() {}

TEST(MP_Scheduler, HasReadyThreads) {
  MP_Scheduler *mp_scheduler = new MP_Scheduler(MP_Scheduler::FCFS, 10);

  EXPECT_NO_THROW(mp_scheduler->has_ready_threads());
};

TEST(MP_Scheduler, AddThread) {
  MP_Scheduler *mp_scheduler = new MP_Scheduler(MP_Scheduler::FCFS, 10);
  MP_Thread *main_thread = new MP_Thread();
  MP_Thread *thread_1 = new MP_Thread(dummy_method2, main_thread, "1");
  MP_Thread *thread_2 = new MP_Thread(dummy_method2, main_thread, "2");

  EXPECT_NO_THROW(mp_scheduler->add_ready(thread_1));
  EXPECT_NO_THROW(mp_scheduler->add_ready(thread_2));
};

