set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/solutions/leetcode)

if (EXISTS ${CMAKE_HOME_DIRECTORY}/solutions/leetcode/CMakeSwitch.txt)
    build_all_cpp(true)
endif()
