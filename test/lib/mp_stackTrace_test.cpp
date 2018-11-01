#include <gtest/gtest.h>
#include "mpStackTrace.h"
template<typename Type>
struct A
{
  struct B
  {
    void func()
    {
      GetStackTrace();
    }

    void func(Type)
    {
      GetStackTrace();
    }
  };
};

TEST(GetStackTrace, EXPECTNOTHROW)
{
  EXPECT_NO_THROW(A<const char*>::B().func("42"));
};
