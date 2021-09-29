#include "gtest/gtest.h"

extern "C" {
#include "slstack.h"
}

TEST(SLStackTest, create_new_stack) {
  SLStack* stack = sls_new();

  EXPECT_NE(stack, nullptr);

  sls_del(stack);
}

TEST(SLStackTest, stack_should_be_empty) {
  SLStack* stack = sls_new();

  EXPECT_TRUE(sls_is_empty(stack));

  sls_del(stack);
}

TEST(SLStackTest, stack_should_not_be_empty) {
  SLStack* stack = sls_new();

  std::string names[] = {"John"};

  sls_push(stack, &names[0]);

  EXPECT_FALSE(sls_is_empty(stack));

  sls_del(stack);
}

TEST(SLStackTest, non_empty_stack_should_be_empty_after_removal_of_all_elements) {
  SLStack* stack = sls_new();

  std::string super_heroes[] = {"Batman", "Spiderman", "Superman"};

  sls_push(stack, &names[0]);
  sls_push(stack, &names[1]);
  sls_push(stack, &names[2]);

  EXPECT_FALSE(sls_is_empty(stack));

  sls_pop(stack);
  sls_pop(stack);
  sls_pop(stack);

  EXPECT_TRUE(sls_is_empty(stack));

  sls_del(stack);
}
