add_executable(stat_test src/maintest.cpp src/stattest.cpp)

target_link_libraries(stat_test stat GTest::Main)
add_test(NAME stat_test COMMAND stat_test)
