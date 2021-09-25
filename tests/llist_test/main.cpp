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

TEST(LListTest, get_data_at_index_from_llist) {
  std::string names[]{"John", "Conman", "Doe"};

  LList* llist = new_list();

  append_data(llist, &names[0]);
  append_data(llist, &names[1]);
  append_data(llist, &names[2]);

  EXPECT_EQ(len_list(llist), sizeof(names)/sizeof(names[0]));

  std::string* data_at_index_1 = static_cast<std::string*>(ll_get_data(llist, 1));
  std::string* data_at_index_2 = static_cast<std::string*>(ll_get_data(llist, 2));

  EXPECT_STREQ((*data_at_index_1).c_str(), names[1].c_str());
  EXPECT_STREQ((*data_at_index_2).c_str(), names[2].c_str());

  del_list(llist);
}

TEST(LListTest, get_data_at_non_existant_index_from_llist) {
  std::string names[]{"John", "Conman", "Doe"};

  LList* llist = new_list();

  append_data(llist, &names[0]);
  append_data(llist, &names[1]);
  append_data(llist, &names[2]);

  EXPECT_EQ(len_list(llist), sizeof(names)/sizeof(names[0]));

  std::string* data_at_index = static_cast<std::string*>(ll_get_data(llist, len_list(llist)));

  EXPECT_EQ(data_at_index, nullptr);

  del_list(llist);
}
