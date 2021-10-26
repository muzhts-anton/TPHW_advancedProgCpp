add_library(stat STATIC src/stat.c)

target_include_directories(stat PUBLIC include)

add_subdirectory(tests)
