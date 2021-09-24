#include "gtest/gtest.h"

extern "C" {
#include "llist.h"
}

TEST(LListTest, create_new_llist) {
  LList *llist = new_list();

  EXPECT_NE(llist, nullptr);

  del_list(llist);
}