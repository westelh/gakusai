add_executable(utils_test utils_test.cpp)
target_link_libraries(utils_test ${GTEST_BOTH_LIBRARIES} utils)

add_test(utils utils_test)
INCLUDE_DIRECTORIES(${PROJECT_ROOT}/src/utils)