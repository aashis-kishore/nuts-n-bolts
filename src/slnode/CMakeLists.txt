add_library(slnode)

file(GLOB SLNODE_SRC "*.c")

target_sources(slnode PRIVATE ${SLNODE_SRC})

target_include_directories(slnode INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_custom_command(
  TARGET slnode
  PRE_BUILD
  COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/slnode.h
          ${CMAKE_INCLUDE_OUTPUT_DIRECTORY})
