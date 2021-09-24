add_library(lnode)

file(GLOB LNODE_SRC "*.c")

target_sources(lnode PRIVATE ${LNODE_SRC})

target_include_directories(lnode INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_custom_command(TARGET lnode
  PRE_BUILD
  COMMAND cp ${CMAKE_CURRENT_SOURCE_DIR}/lnode.h ${CMAKE_INCLUDE_OUTPUT_DIRECTORY}
)
