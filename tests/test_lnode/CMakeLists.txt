addTest(test_lnode ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp lnode)

if (BUILD_TESTS)
  gtest_discover_tests(test_lnode)
endif()
