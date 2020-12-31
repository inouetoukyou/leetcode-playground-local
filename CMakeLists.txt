cmake_minimum_required(VERSION 3.14)
project(oj)
set(CMAKE_CXX_STANDARD 17)
#https://support.leetcode.com/hc/en-us/articles/360011833974-What-are-the-environments-for-the-programming-languages-
#clang10 c++17
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -fsanitize=address,undefined)
include_directories(include)

FUNCTION(build_all_cpp INPUT_FROM_FILE)
    FILE(GLOB_RECURSE SRC_FILES "*.cpp")
    FOREACH(FILE_PATH ${SRC_FILES})
        STRING(REGEX REPLACE ".+/(.+)\\..*" "\\1" FILE_NAME ${FILE_PATH})
        add_executable(${FILE_NAME} ${FILE_NAME}.cpp)
        IF(INPUT_FROM_FILE)
            target_compile_definitions(${FILE_NAME} PRIVATE -DINPUT_FROM_FILE)
        ENDIF()
    ENDFOREACH(FILE_PATH)
endfunction()

add_subdirectory(demos)
add_subdirectory(mains)
add_subdirectory(tests)
add_subdirectory(solutions/leetcode)
add_subdirectory(solutions/lintcode)
