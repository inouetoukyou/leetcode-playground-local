set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/tests)

add_executable(test1 test1.cpp)
add_executable(test2 test2.cpp)
target_compile_definitions(test2 PRIVATE -DLOCAL)
add_executable(test3 test3.cpp)
target_compile_definitions(test3 PRIVATE -DLOCAL)
