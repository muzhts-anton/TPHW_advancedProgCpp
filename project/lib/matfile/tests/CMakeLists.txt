add_executable(parser_test src/maintest.cpp src/parsertest.cpp)

target_link_libraries(parser_test parser GTest::Main)
add_test(NAME parser_test COMMAND parser_test)
