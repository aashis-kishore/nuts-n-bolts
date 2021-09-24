#include "gtest/gtest.h"

extern "C" {
  #include "lnode.h"
}

TEST(TestLNode, sum_to_numbers) {
  int x = 10, y = 20;
  EXPECT_EQ(x + y, 30);
}
