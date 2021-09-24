#include "gtest/gtest.h"

extern "C" {
  #include "lnode.h"
}

TEST(LNodeTest, create_new_lnode) {
  std::string name = "Aashis Kishore";
  LNode* lnode = new_node(&name);

  EXPECT_NE(lnode, nullptr);

  del_node(lnode);
}

TEST(LNodeTest, create_two_lnodes_and_link) {
  std::string first_name = "Aashis";
  std::string last_name = "Kishore";

  LNode* fname = new_node(&first_name);
  LNode* lname = new_node(&last_name);

  link_node(fname, lname);

  EXPECT_EQ(next_node(fname), lname);

  del_node(fname);
  del_node(lname);
}