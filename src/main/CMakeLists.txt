set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_ROOT}/exe)
add_executable(main
	main.cpp
)

target_link_libraries(main ${OpenCV_LIBS} utils)
INCLUDE_DIRECTORIES(${PROJECT_ROOT}/src/utils)