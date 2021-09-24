cmake_minimum_required(VERSION 3.10)

cmake_policy(SET CMP0048 NEW)

project(
  nuts-n-bolts
  VERSION 0.0.1
  DESCRIPTION "An attempt to implement to fundamental datastructures and algorithms"
  LANGUAGES C
)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)
