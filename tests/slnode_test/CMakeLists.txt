addtest(slnode_test ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp slnode)

if(BUILD_TESTS)
  gtest_discover_tests(slnode_test)
endif()
