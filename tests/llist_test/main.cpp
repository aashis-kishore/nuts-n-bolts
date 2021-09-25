#include "gtest/gtest.h"

extern "C" {
#include "llist.h"
}

TEST(LListTest, create_new_llist) {
  LList* llist = new_list();

  EXPECT_NE(llist, nullptr);

  del_list(llist);
}

TEST(LListTest, append_data_into_llist) {
  std::string names[]{"John", "Conman", "Doe"};

  LList* llist = new_list();

  append_data(llist, &names[0]);
  append_data(llist, &names[1]);
  append_data(llist, &names[2]);

  EXPECT_EQ(len_list(llist), sizeof(names)/sizeof(names[0]));

  del_list(llist);
}