cmake_minimum_required(VERSION 3.5.2)
project(gakusai)

set(CMAKE_COMPILER_C gcc)
set(CMAKE_COMPILER_CXX g++)
add_definitions("-Wall -std=c++14")

add_subdirectory(src/main)
