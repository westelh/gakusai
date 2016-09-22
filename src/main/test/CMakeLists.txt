add_executable(maintest maintest.cpp)
target_link_libraries(maintest ${GTEST_BOTH_LIBRARIES})
add_test(main maintest)
