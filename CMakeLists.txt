cmake_minimum_required(VERSION 3.0.0)
project(graph VERSION 0.1.0 LANGUAGES C)

include(CTest)
enable_testing()

add_library(graph SHARED
    src/core/edge.c
    src/core/graph.c
    src/core/vertice.c
)

set_target_properties(graph PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER include/graph.h
)

target_include_directories(graph PRIVATE include)

add_executable(c_test 
    test/edge_test.c
)
target_include_directories(c_test PRIVATE include)
target_link_libraries(c_test PRIVATE graph)

add_test(
    NAME c_test
    COMMAND $<TARGET_FILE:c_test>
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
