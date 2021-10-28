cmake_minimum_required(VERSION 3.16)

project(pro)

# add_compile_options(--coverage)
# add_link_options(--coverage)

find_package(GTest)
enable_testing()

add_subdirectory(project/lib/sequential_sum)
add_subdirectory(project/lib/matfile)

add_executable(yoyo project/src/main.c)

target_link_libraries(yoyo parser stat)
