cmake_minimum_required(VERSION 3.8)
project(Task1)

set(CMAKE_C_FLAGS "--coverage") # ?

set(CMAKE_C_STANDARD 11)

configure_file(CMakeLists.txt.in
        googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build)

enable_testing()
add_subdirectory(project/tst)

include_directories("${PROJECT_SOURCE_DIR}/project/include")
file(GLOB sources
  "${PROJECT_SOURCE_DIR}/project/include/*.h"
  "${PROJECT_SOURCE_DIR}/project/src/*.c")
add_executable(task1.out ${sources})