set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_ROOT}/lib/static)
add_library(utils STATIC
  argv_to_vec.cpp)