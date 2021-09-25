addtest(sllist_test ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp sllist)

if(BUILD_TESTS)
  gtest_discover_tests(sllist_test)
endif()
