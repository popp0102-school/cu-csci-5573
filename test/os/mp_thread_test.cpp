#include <gtest/gtest.h>
#include "mp_thread.h"

void some_dummy_method() {}

TEST(MP_Thread, default_constructor) {
  MP_Thread *some_thread = new MP_Thread();
  EXPECT_NO_THROW(some_thread->get_context());
};

TEST(MP_Thread, non_default_constructor) {
  MP_Thread *main_thread = new MP_Thread();
  MP_Thread *some_thread = new MP_Thread(some_dummy_method, main_thread);
  EXPECT_NO_THROW(some_thread->get_context());
};

