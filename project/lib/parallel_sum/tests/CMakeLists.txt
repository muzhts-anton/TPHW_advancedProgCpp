add_executable(paral_test src/maintest.cpp src/paraltest.cpp)

target_link_libraries(paral_test paral GTest::Main)
add_test(NAME paral_test COMMAND paral_test)
