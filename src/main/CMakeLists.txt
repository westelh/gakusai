set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_ROOT}/exe)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_ROOT}/lib/static)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_ROOT}/lib/dynamic)
add_executable(main
	main.cpp
)

target_link_libraries(main ${OpenCV_LIBS})
