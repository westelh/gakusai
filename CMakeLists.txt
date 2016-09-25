# project settings
cmake_minimum_required(VERSION 3.5.2)
project(gakusai)
set(PROJECT_ROOT ${CMAKE_CURRENT_LIST_DIR})

# compiler & linker setup
add_definitions("-Wall -std=c++14")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -DDEBUG")

# required packages
find_package(GTest REQUIRED)
find_package(OpenCV REQUIRED)

# test
enable_testing()
include_directories(${GTEST_INCLUDE_DIRS})

# sub directories
add_subdirectory(src/main)
add_subdirectory(src/main/test)
add_subdirectory(src/utils)
add_subdirectory(src/utils/test)