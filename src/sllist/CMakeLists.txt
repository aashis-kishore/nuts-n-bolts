add_library(sllist)

file(GLOB SLLIST_SRC "*.c")

target_sources(sllist PRIVATE ${SLLIST_SRC})

target_include_directories(
  sllist
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
  PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(sllist PRIVATE slnode)

add_custom_command(
  TARGET sllist
  PRE_BUILD
  COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/sllist.h
          ${CMAKE_INCLUDE_OUTPUT_DIRECTORY})
