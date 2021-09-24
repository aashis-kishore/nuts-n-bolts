add_library(llist)

file(GLOB LLIST_SRC "*.c")

target_sources(llist PRIVATE ${LLIST_SRC})

target_include_directories(
  llist
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
  PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(llist PRIVATE lnode)

add_custom_command(
  TARGET llist
  PRE_BUILD
  COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/llist.h
          ${CMAKE_INCLUDE_OUTPUT_DIRECTORY})
