add_library(lnode)

file(GLOB LNODE_SRC "*.c")

target_sources(lnode PRIVATE ${LNODE_SRC})

target_include_directories(lnode INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
