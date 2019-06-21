cmake_minimum_required(VERSION 3.14)
project(oj)

set(CMAKE_CXX_STANDARD 11)

add_executable(oj main.cpp leetcode/treenode.h leetcode/stringtool.h leetcode/stringtool.cpp leetcode/treenode.cpp)