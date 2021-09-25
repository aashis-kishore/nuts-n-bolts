#include "gtest/gtest.h"

extern "C" {
#include "sllist.h"
}

TEST(SLListTest, create_new_list) {
  SLList* list = sll_new_list();

  EXPECT_NE(list, nullptr);

  sll_del_list(list);
}

TEST(SLListTest, append_data_into_list) {
  std::string names[]{"John", "Conman", "Doe"};

  SLList* list = sll_new_list();

  sll_append_data(list, &names[0]);
  sll_append_data(list, &names[1]);
  sll_append_data(list, &names[2]);

  EXPECT_EQ(sll_len_list(list), sizeof(names)/sizeof(names[0]));

  sll_del_list(list);
}

TEST(SLListTest, get_data_at_index_from_llist) {
  std::string names[]{"John", "Conman", "Doe"};

  SLList* list = sll_new_list();

  sll_append_data(list, &names[0]);
  sll_append_data(list, &names[1]);
  sll_append_data(list, &names[2]);

  EXPECT_EQ(sll_len_list(list), sizeof(names)/sizeof(names[0]));

  std::string* data_at_index_1 = static_cast<std::string*>(sll_get_data(list, 1));
  std::string* data_at_index_2 = static_cast<std::string*>(sll_get_data(list, 2));

  EXPECT_STREQ((*data_at_index_1).c_str(), names[1].c_str());
  EXPECT_STREQ((*data_at_index_2).c_str(), names[2].c_str());

  sll_del_list(list);
}

TEST(SLListTest, get_data_at_non_existant_index_from_list) {
  std::string names[]{"John", "Conman", "Doe"};

  SLList* list = sll_new_list();

  sll_append_data(list, &names[0]);
  sll_append_data(list, &names[1]);
  sll_append_data(list, &names[2]);

  EXPECT_EQ(sll_len_list(list), sizeof(names)/sizeof(names[0]));

  std::string* data_at_index = static_cast<std::string*>(sll_get_data(list, sll_len_list(list)));

  EXPECT_EQ(data_at_index, nullptr);

  sll_del_list(list);
}
