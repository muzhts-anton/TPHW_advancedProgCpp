cmake_minimum_required(VERSION 3.16)

project(pro)

option(COVERAGE "To get a test coverage" OFF)
if(COVERAGE)
    add_compile_options(--coverage)
    add_link_options(--coverage)
endif()

option(SANITAIZE "To get sanitaize test" OFF)
if(SANITAIZE)
    add_compile_options(-fno-omit-frame-pointer -fsanitize=address)
    add_link_options(-fsanitize=address)
endif()

add_compile_options(-Wall -Werror -Wpedantic)

option(BUILD_PARAL "Build with parallel library" OFF)
if(BUILD_PARAL)
    add_compile_options(-DBUILD_PARAL)
endif()

find_package(GTest)
enable_testing()

add_subdirectory(project/lib/sequential_sum)
add_subdirectory(project/lib/matfile)
add_subdirectory(project/lib/parallel_sum)

add_executable(yoyo project/src/main.c)

if(BUILD_PARAL)
    target_link_libraries(yoyo parser paral)
else()
    target_link_libraries(yoyo parser stat)
endif()
