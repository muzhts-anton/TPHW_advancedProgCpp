cmake_minimum_required(VERSION 3.10)

project(Task1)

add_library(foo STATIC project/src/rdnetwork.c)
add_executable(main project/src/main.c)
target_link_libraries(main foo)
