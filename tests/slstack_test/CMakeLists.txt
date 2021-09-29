addtest(slstack_test ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp slstack)

if(BUILD_TESTS)
  gtest_discover_tests(slstack_test)
endif()
