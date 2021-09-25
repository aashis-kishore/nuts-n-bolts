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

TEST(SLListTest, insert_data_at_index_in_list) {
  std::string names[]{"Mr", "John", "Conman", "Doe", "Well-known"};

  SLList* list = sll_new();

  sll_append(list, &names[1]);
  sll_append(list, &names[3]);

  sll_insert(list, &names[0], 0);
  std::string* name = static_cast<std::string*>(sll_data(list, 0));
  EXPECT_STREQ((*name).c_str(), names[0].c_str());

  sll_insert(list, &names[2], 2);
  name = static_cast<std::string*>(sll_data(list, 2));
  EXPECT_STREQ((*name).c_str(), names[2].c_str());

  sll_insert(list, &names[4], 4);
  name = static_cast<std::string*>(sll_data(list, 4));
  EXPECT_STREQ((*name).c_str(), names[4].c_str());

  EXPECT_EQ(sll_len(list), 5);

  size_t len = sll_len(list);
  sll_insert(list, &names[0], len);
  name = static_cast<std::string*>(sll_data(list, len));
  EXPECT_STREQ((*name).c_str(), names[0].c_str());

  sll_del(list);
}
