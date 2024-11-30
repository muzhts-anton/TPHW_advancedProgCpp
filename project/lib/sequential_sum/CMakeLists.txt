add_library(stat STATIC src/stat.c)

target_include_directories(stat PUBLIC include)
target_link_libraries(stat PUBLIC parser)

add_subdirectory(tests)
