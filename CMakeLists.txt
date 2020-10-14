cmake_minimum_required(VERSION 3.14)
project(oj)
set(CMAKE_CXX_STANDARD 17)
#https://support.leetcode.com/hc/en-us/articles/360011833974-What-are-the-environments-for-the-programming-languages-
#clang10 c++17
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -fsanitize=address,undefined)
include_directories(include)

function(build_all_cpp is_local)
    FILE(GLOB_RECURSE SRC_FILES "*.cpp")
    FOREACH(FILE_PATH ${SRC_FILES})
        STRING(REGEX REPLACE ".+/(.+)\\..*" "\\1" FILE_NAME ${FILE_PATH})
        add_executable(${FILE_NAME} ${FILE_NAME}.cpp)
        if (is_local)
            target_compile_definitions(${FILE_NAME} PRIVATE -DLOCAL)
        endif()
    ENDFOREACH(FILE_PATH)
endfunction()

add_subdirectory(demos)
add_subdirectory(mains)
add_subdirectory(solutions/leetcode)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_executable(test1 test1.cpp)
add_executable(test2 test2.cpp)
target_compile_definitions(test2 PRIVATE -DLOCAL)
add_executable(test3 test3.cpp)
target_compile_definitions(test3 PRIVATE -DLOCAL)
