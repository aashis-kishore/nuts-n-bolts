cmake_minimum_required(VERSION 3.14)

cmake_policy(SET CMP0048 NEW)

project(
  nuts-n-bolts
  VERSION 0.0.1
  DESCRIPTION "An attempt to implement to fundamental datastructures and algorithms"
  LANGUAGES C CXX
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_INCLUDE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/include)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)

# include(ExternalProject)

# if(NOT CMAKE_BUILD_TYPE)
#   set(CMAKE_BUILD_TYPE Release)
# endif()

# set_directory_properties(PROPERTIES EP_PREFIX ${CMAKE_BINARY_DIR}/ThirdParty)

# ExternalProject_Add(
#   googletest
#   URL https://github.com/google/googletest/archive/release-1.10.0.zip
#   PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
#   # Disable install step
#   CMAKE_ARGS -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
#              -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG:PATH=DebugLibs
#              -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE:PATH=ReleaseLibs
#              -Dgtest_force_shared_crt=ON
#   INSTALL_COMMAND ""
#   # Wrap download, configure and build steps in a script to log output
#   LOG_DOWNLOAD ON
#   LOG_CONFIGURE ON
#   LOG_BUILD ON
# )

# # Specify include dir
# ExternalProjects_Get_Property(googletest source_dir)
# include_directories(${source_dir}/include)

option(BUILD_TESTS "Build included tests" ON)

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
