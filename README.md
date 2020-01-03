# LeetCode Playground Local  
[中文版](README.ZH.md)
## Description
This is an input helper for LeetCode. When we solve the problems in LeetCode, we can only see a Solution class, which is inconvenient to debug. But this project can help we convert `string` to other data types that we want, such as `vector<T>`, `ListNode<T>` and `TreeNode<T>`.

## Compiler
Clang with c++11 is recommended  
G++-6 and above are recommended  
G++-5 is ok but not recommended  
G++-4.9 and below are not supported  

## Hint
1. In the top level directory, the `test.cpp` shows:  
a. how to parse `string` to `ListNode`, `TreeNode` and `vector`  
b. how to handle input through a file  
2. In subdirectory `demos`, you can  
a. see how to parse `string` to other types  
`vector<vector<char>>` (`char_doublevector.cpp`)  
`vector<Interval>` (`custom_vector.cpp`)  
`vector<vector<int>>` (`doublevector.cpp`)  
`vector<string>` (`stringvector.cpp`)  
`ListNode<int>` (`test_listnode.cpp`)  
`TreeNode<int>` (`test_treenode.cpp`)  
b. get input through command line (`big_input.cpp`)  
c. get input from file (`file_input.cpp` & `file_input2.cpp`)
3. In subdirectory `solutions`, there are solutions to LeetCode problems.
## Usage 
1. command line mode  
`$ cp CMakeLists.txt.copy CMakeLists.txt`  
`$ mkdir build`  
`$ cd build`  
`$ cmake ..`  
`$ make`  
`$ cd bin`  
`$ ls`  
you can see all executable files.
2. IDE mode (such as CLion)  
a. Copy `CMakeLists.txt.copy` as `CMakeLists.txt`  
b. Create `main.cpp` in top level directory.  
c. In `CMakeLists.txt`, add code `add_executable(main main.cpp)` after the last line.  
d. Complete `main.cpp` followed the examples in `test.cpp` or files in dir `solutions` and `demos`.(If you want to compile the codes in `solutions`, remove the `#` at line 15 in `CMakeLists.txt`)  
e. Build your projects and debug.
