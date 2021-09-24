cmake_minimum_required(VERSION 3.14)

cmake_policy(SET CMP0048 NEW)

project(
  nuts-n-bolts
  VERSION 0.1.0
  DESCRIPTION "An attempt to implement to fundamental datastructures and algorithms"
  LANGUAGES C CXX
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_INCLUDE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/include)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)

option(BUILD_TESTS "Build included tests" OFF)

if(BUILD_TESTS)
  include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
    # CMAKE_ARGS -DBUILD_GMOCK=OFF
  )

  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)

  enable_testing()
  include(GoogleTest)

  add_subdirectory(${PROJECT_SOURCE_DIR}/tests)
endif()
