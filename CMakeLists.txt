cmake_minimum_required(VERSION 3.16)

project(Task1)

set(CMAKE_CXX_STANDART 14)

include_directories("${PROJECT_SOURCE_DIR}/project/include")
file(GLOB sources
    "${PROJECT_SOURCE_DIR}/project/include/*.h"
    "${PROJECT_SOURCE_DIR}/project/src/*.c")

add_executable(main ${sources})