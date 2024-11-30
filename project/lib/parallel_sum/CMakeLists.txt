add_library(paral SHARED src/paral.c)

target_include_directories(paral PUBLIC include)
target_link_libraries(paral PUBLIC parser)

add_subdirectory(tests)