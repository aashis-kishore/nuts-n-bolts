#include "gtest/gtest.h"

extern "C" {
#include "slstack.h"
}

TEST(SLStackTest, create_new_stack) {
  SLStack* stack = sls_new();

  EXPECT_NE(stack, nullptr);

  sls_del(stack);
}
