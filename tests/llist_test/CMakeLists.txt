addTest(llist_test ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp llist)

if (BUILD_TESTS)
  gtest_discover_tests(llist_test)
endif()