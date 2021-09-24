#include "gtest/gtest.h"

extern "C" {
  #include "lnode.h"
}

TEST(LNodeTest, create_new_lnode) {
  std::string name = "John Doe";
  LNode* lnode = new_node(&name);

  EXPECT_NE(lnode, nullptr);

  del_node(lnode);
}

TEST(LNodeTest, create_two_lnodes_and_link) {
  std::string first_name = "John";
  std::string last_name = "Doe";

  LNode* fname = new_node(&first_name);
  LNode* lname = new_node(&last_name);

  link_node(fname, lname);

  EXPECT_EQ(next_node(fname), lname);

  del_node(fname);
  del_node(lname);
}

TEST(LNodeTest, create_three_lnodes_and_link) {
  std::string first_name = "John";
  std::string middle_name = "Conman";
  std::string last_name = "Doe";

  LNode* fname = new_node(&first_name);
  LNode* mname = new_node(&middle_name);
  LNode* lname = new_node(&last_name);

  link_node(fname, mname);
  link_node(mname, lname);

  EXPECT_EQ(next_node(fname), mname);
  EXPECT_EQ(next_node(mname), lname);

  del_node(fname);
  del_node(mname);
  del_node(lname);
}