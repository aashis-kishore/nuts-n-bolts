add_library(slstack)

file(GLOB SLSTACK_SRC "*.c")

target_sources(slstack PRIVATE ${SLSTACK_SRC})

target_include_directories(slstack INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(slstack PRIVATE sllist)

add_custom_command(
  TARGET slstack
  PRE_BUILD
  COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/slstack.h
          ${CMAKE_INCLUDE_OUTPUT_DIRECTORY})
