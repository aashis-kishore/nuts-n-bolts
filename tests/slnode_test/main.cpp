#include "gtest/gtest.h"

extern "C" {
#include "slnode.h"
}

TEST(SLNodeTest, create_new_node) {
  std::string name = "John Doe";
  SLNode* node = sln_new_node(&name);

  EXPECT_NE(node, nullptr);

  sln_del_node(node);
}

TEST(SLNodeTest, create_two_nodes_and_link) {
  std::string first_name = "John";
  std::string last_name = "Doe";

  SLNode* fname = sln_new_node(&first_name);
  SLNode* lname = sln_new_node(&last_name);

  sln_link_node(fname, lname);

  EXPECT_EQ(sln_next_node(fname), lname);

  sln_del_node(fname);
  sln_del_node(lname);
}

TEST(SLNodeTest, create_three_nodes_and_link) {
  std::string first_name = "John";
  std::string middle_name = "Conman";
  std::string last_name = "Doe";

  SLNode* fname = sln_new_node(&first_name);
  SLNode* mname = sln_new_node(&middle_name);
  SLNode* lname = sln_new_node(&last_name);

  sln_link_node(fname, mname);
  sln_link_node(mname, lname);

  EXPECT_EQ(sln_next_node(fname), mname);
  EXPECT_EQ(sln_next_node(mname), lname);

  sln_del_node(fname);
  sln_del_node(mname);
  sln_del_node(lname);
}

TEST(SLNodeTest, store_and_retrieve_data) {
  std::string full_name = "John Conman Doe";

  SLNode* name = sln_new_node(&full_name);

  std::string* data = static_cast<std::string*>(sln_get_data(name));

  EXPECT_STREQ((*data).c_str(), full_name.c_str());

  sln_del_node(name);
}

TEST(SLNodeTest, store_retrieve_composite_data) {
  struct Person {
    std::string name;
    int age;
  };

  Person student{"John Doe", 25};

  SLNode* person = sln_new_node(&student);

  std::string name = static_cast<Person*>(sln_get_data(person))->name;
  int age = static_cast<Person*>(sln_get_data(person))->age;

  EXPECT_STREQ(name.c_str(), student.name.c_str());
  EXPECT_EQ(age, student.age);

  sln_del_node(person);
}