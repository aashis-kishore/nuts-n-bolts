#include "gtest/gtest.h"

extern "C" {
#include "slnode.h"
}

TEST(SLNodeTest, create_new_node) {
  std::string name = "John Doe";
  SLNode* node = sln_new(&name);

  EXPECT_NE(node, nullptr);

  sln_del(node);
}

TEST(SLNodeTest, create_two_nodes_and_link) {
  std::string first_name = "John";
  std::string last_name = "Doe";

  SLNode* fname = sln_new(&first_name);
  SLNode* lname = sln_new(&last_name);

  sln_link(fname, lname);

  EXPECT_EQ(sln_next(fname), lname);

  sln_del(fname);
  sln_del(lname);
}

TEST(SLNodeTest, create_three_nodes_and_link) {
  std::string first_name = "John";
  std::string middle_name = "Conman";
  std::string last_name = "Doe";

  SLNode* fname = sln_new(&first_name);
  SLNode* mname = sln_new(&middle_name);
  SLNode* lname = sln_new(&last_name);

  sln_link(fname, mname);
  sln_link(mname, lname);

  EXPECT_EQ(sln_next(fname), mname);
  EXPECT_EQ(sln_next(mname), lname);

  sln_del(fname);
  sln_del(mname);
  sln_del(lname);
}

TEST(SLNodeTest, store_and_retrieve_data) {
  std::string full_name = "John Conman Doe";

  SLNode* name = sln_new(&full_name);

  std::string* data = static_cast<std::string*>(sln_data(name));

  EXPECT_STREQ((*data).c_str(), full_name.c_str());

  sln_del(name);
}

TEST(SLNodeTest, store_retrieve_composite_data) {
  struct Person {
    std::string name;
    int age;
  };

  Person student{"John Doe", 25};

  SLNode* person = sln_new(&student);

  std::string name = static_cast<Person*>(sln_data(person))->name;
  int age = static_cast<Person*>(sln_data(person))->age;

  EXPECT_STREQ(name.c_str(), student.name.c_str());
  EXPECT_EQ(age, student.age);

  sln_del(person);
}
