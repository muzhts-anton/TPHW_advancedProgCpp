add_library(parser STATIC src/parser.c)

target_include_directories(parser PUBLIC include)

add_subdirectory(tests)