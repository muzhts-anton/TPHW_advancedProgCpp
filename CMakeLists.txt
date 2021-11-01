cmake_minimum_required(VERSION 3.16)

project(pro)

# add_compile_options(--coverage)
# add_link_options(--coverage)

# add_compile_options(-fno-omit-frame-pointer -fsanitize=address)
# add_link_options(-fsanitize=address)

find_package(GTest)
enable_testing()

add_subdirectory(project/lib/sequential_sum)
add_subdirectory(project/lib/matfile)
add_subdirectory(project/lib/parallel_sum)

add_executable(yoyo project/src/main.c)

target_link_libraries(yoyo parser paral stat)
