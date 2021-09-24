addTest(lnode_test ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp lnode)

if (BUILD_TESTS)
  gtest_discover_tests(lnode_test)
endif()
