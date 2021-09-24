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
