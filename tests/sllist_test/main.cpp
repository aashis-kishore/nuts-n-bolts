#include "gtest/gtest.h"

extern "C" {
#include "sllist.h"
}

TEST(SLListTest, create_new_list) {
  SLList* list = sll_new();

  EXPECT_NE(list, nullptr);

  sll_del(list);
}

TEST(SLListTest, append_data_into_list) {
  std::string names[]{"John", "Conman", "Doe"};

  SLList* list = sll_new();

  sll_append(list, &names[0]);
  sll_append(list, &names[1]);
  sll_append(list, &names[2]);

  EXPECT_EQ(sll_len(list), sizeof(names) / sizeof(names[0]));

  sll_del(list);
}

TEST(SLListTest, get_data_at_index_from_llist) {
  std::string names[]{"John", "Conman", "Doe"};

  SLList* list = sll_new();

  sll_append(list, &names[0]);
  sll_append(list, &names[1]);
  sll_append(list, &names[2]);

  EXPECT_EQ(sll_len(list), sizeof(names) / sizeof(names[0]));

  std::string* data_at_index_1 = static_cast<std::string*>(sll_data(list, 1));
  std::string* data_at_index_2 = static_cast<std::string*>(sll_data(list, 2));

  EXPECT_STREQ((*data_at_index_1).c_str(), names[1].c_str());
  EXPECT_STREQ((*data_at_index_2).c_str(), names[2].c_str());

  sll_del(list);
}

TEST(SLListTest, get_data_at_non_existant_index_from_list) {
  std::string names[]{"John", "Conman", "Doe"};

  SLList* list = sll_new();

  sll_append(list, &names[0]);
  sll_append(list, &names[1]);
  sll_append(list, &names[2]);

  EXPECT_EQ(sll_len(list), sizeof(names) / sizeof(names[0]));

  std::string* data_at_index =
      static_cast<std::string*>(sll_data(list, sll_len(list)));

  EXPECT_EQ(data_at_index, nullptr);

  sll_del(list);
}

TEST(SLListTest, remove_data_at_index_from_list) {
  std::string names[]{"John", "Conman", "Doe"};

  SLList* list = sll_new();

  sll_append(list, &names[0]);
  sll_append(list, &names[1]);
  sll_append(list, &names[2]);

  sll_remove(list, 1);
  EXPECT_EQ(sll_len(list), (sizeof(names) / sizeof(names[0])) - 1);
  sll_remove(list, 0);
  EXPECT_EQ(sll_len(list), (sizeof(names) / sizeof(names[0])) - 2);
  std::string* lname = static_cast<std::string*>(sll_remove(list, 0));
  EXPECT_EQ(sll_len(list), (sizeof(names) / sizeof(names[0])) - 3);
  EXPECT_STREQ((*lname).c_str(), names[2].c_str());
  void* data = sll_remove(list, 0);
  EXPECT_EQ(data, nullptr);
  data = sll_remove(list, 1010);
  EXPECT_EQ(data, nullptr);

  sll_del(list);
}
