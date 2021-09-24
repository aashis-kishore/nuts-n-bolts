macro(addTest TARGET_NAME SOURCES LIBRARIES)
  add_executable(${TARGET_NAME})
  target_sources(${TARGET_NAME} PUBLIC ${SOURCES})
  target_include_directories(
    ${TARGET_NAME}
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
  )
  target_link_libraries(
    ${TARGET_NAME}
    PUBLIC
    ${LIBRARIES} gtest gtest_main -lpthread -no-pie
  )
endmacro()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lnode_test)
