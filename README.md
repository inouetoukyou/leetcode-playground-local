# LeetCode Playground Local  
[中文版](README.ZH.md)
## Description
This is an input helper for LeetCode. When we solve the problems in LeetCode, we can only see a Solution class, which is inconvenient to debug. But this project can help we convert `string` to other data types that we want, such as `vector<T>`, `ListNode<T>` and `TreeNode<T>`.  

## Compiler
Clang with c++17 is recommended  
G++-6 and above are recommended  
G++-5 is ok but not recommended  
G++-4.9 and below are not supported  

## Sanitizer
Install llvm.  
In OSX,  
`brew install llvm`  
`ln -s /usr/local/opt/llvm/bin/llvm-symbolizer /usr/local/bin`

## Hint
1. `test1.cpp` in the top level directory  shows:  
a. how to parse `string` to `ListNode`, `TreeNode` and `vector`  
b. how to output `vector`  
c. how to handle input through a file  
2. `test2.cpp` in the top level directory shows:   
a. how to run a classical two-sum problem  
b. it gets input from the corresponding input file in `input/test2.in` (Note the function`main` and function `sub` ,and refer to `input/helper.h` for details of function `subRoutine`. Finally, please note the last line of `CMakeLists.txt.copy`, which adds definition `LOCAL` to `test2.cpp`.)  
3. In subdirectory `demos`, you can  
a. see how to parse `string` to other types  
`vector<vector<char>>` (`char_doublevector.cpp`)  
`vector<Interval>` (`custom_vector.cpp`)  
`vector<vector<int>>` (`doublevector.cpp`)  
`vector<string>` (`stringvector.cpp`)  
`ListNode<int>` (`test_listnode.cpp`)  
`TreeNode<int>` (`test_treenode.cpp`)  
b. get input through command line (`big_input.cpp`)  
c. get input from file (`file_input.cpp` & `file_input2.cpp`)  
4. In subdirectory `solutions`, there are solutions to LeetCode problems.  

## Usage 
1. command line mode  
If you want to compile the codes in `solutions`, create `CMakeSwitch.txt` in `solutions` .  
`$ touch solutions/CMakeSwitch.txt` (optional)  
`$ mkdir build`  
`$ cd build`  
`$ cmake ..`  
`$ make`  
`$ cd bin`  
`$ ls`  
you can see all executable files.

2. IDE mode (such as CLion)  
a. If you want to compile the codes in `solutions`, create `CMakeSwitch.txt` in `solutions` .  
b. Write source files in directory `mains` (such as `main.cpp` ) and optional associated input files in `input/mains` (such as `main.in` ).  
c. Format of `main.cpp` can be referred to the examples in `test1.cpp` , `test2.cpp` or files in dir `solutions` and `demos`.  
e. Build and debug.  
e. Every time you add new source files, you can click Tools->CMake->Reload CMake Project to refresh CMake configuration if you use CLion.  
