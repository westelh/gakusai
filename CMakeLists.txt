cmake_minimum_required(VERSION 3.5.2)
project(gakusai)

add_definitions("-Wall -std=c++14")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -DDEBUG")

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_subdirectory(src/main)
add_subdirectory(src/main/test)