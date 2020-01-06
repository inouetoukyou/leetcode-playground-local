# LeetCode Playground Local  
[English version](README.md)
## 简介
这是一个LeetCode的输入助手。我们做LeetCode题目的时候，只有一个Solution类，不方便我们调试。通过本工具，我们可以很方便地将`string`转化为题目需要的类型，比如`vector<T>`, `ListNode<T>` 以及 `TreeNode<T>`.  

## 编译器
Clang需要支持c++11。  
G++建议使用6及以上的版本。  
G++-5可以运行，但是不建议使用。  
不支持G++-4.9及以下的版本。  

## 提示
1. 最上层目录的 `test1.cpp` 展示：  
a. 如何将 `string` 解析成 `ListNode`, `TreeNode` 以及 `vector`  
b. 如何输出 `vector`  
c. 如何从文件中读取输入   
2. 最上层目录的 `test2.cpp` 展示：  
a. 如何运行一个经典的 two-sum 问题  
b. 该程序从对应的 `input/test2.in` 中读取输入（请留意 `main` 函数和 `sub` 函数，`subRoutine` 函数请参照 `input/helper.h` 。最后查看 `CMakeLists.txt.copy` 最后一行，它为 `test2.cpp` 添加 `LOCAL` 定义。）  
3. 子文件夹 `demos`展示    
a. 如何把 `string` 解析为其他类型  
`vector<vector<char>>` (`char_doublevector.cpp`)  
`vector<Interval>` (`custom_vector.cpp`)  
`vector<vector<int>>` (`doublevector.cpp`)  
`vector<int>` (`int_vector.cpp`)  
`vector<string>` (`stringvector.cpp`)  
`ListNode<int>` (`test_listnode.cpp`)  
`TreeNode<int>` (`test_treenode.cpp`)  
b. 从命令行读取输入 (`big_input.cpp`)  
c. 从文件读取输入 (`file_input.cpp` & `file_input2.cpp`)  
4. 子文件夹 `solutions` 里有LeetCode的部分答案。  

## 使用说明 
1. 命令行方式  
`$ cp CMakeLists.txt.copy CMakeLists.txt`  
`$ mkdir build`  
`$ cd build`  
`$ cmake ..`  
`$ make`  
`$ cd bin`  
`$ ls`  
你将看到所有可执行文件.
2. IDE 模式 (比如 CLion)  
a. 复制 `CMakeLists.txt.copy` 并命名为 `CMakeLists.txt`  
b. 在顶层目录创建 `main.cpp`.  
c. 在 `CMakeLists.txt` 的最后添加 `add_executable(main main.cpp)`.  
d. 仿照 `test1.cpp` ， `test2.cpp`或文件夹 `solutions` 和 `demos` 里的文件完成 `main.cpp`。（如果要编译 `solutions` 里的代码，请把 `CMakeLists.txt` 里第18行的 `#` 去掉）  
e. 编译和调试。  
