# Solutions  
[中文版](README.ZH.md)
## Descriptions
&emsp;This directory contains some solutions of LeetCode.
## Usage
### include
```c++
#include <helper.h>
#include <map> // if necessary
#include <set> // in necessary
using namespace std;
```
### ListNode
```c++
using T = int;
ListNode = ymh::GenericListNode<T>;
```
### code template
```c++
class Solution {}
int sub() {
    Solution solution;
    string s;
    while (getline(cin, s)) {
        
    }
}
```
&emsp;Please refer to `include/helerp.h` for details of function `subRoutine`  
&emsp;Please complete the algorithm in class `Solution`.  
&emsp;In function `sub()`, please convert the input to data structure you want, then call the function in `Solution`.
### input
&emsp;By default, a program will get input from files not terminal. Such source files have a corresponding input files in directory `input/solutions/`.  Some special programs will not, for example *intersection-of-two-linked-lists* .  
&emsp;If you want to use this template, you should creat the corresponding input file in `input/solutions/` after creating the source file in `solutions`.  
&emsp;Because the executable files (based IDE CLion) are in `cmake-build-debug/bin/solutions` , so the default value of 4th argument of function `subRoutine` is `const char* relative = "/../../../input/solutions/"` . If you want to use this template in source files in top-level directories, because the corresponding executable files are in `cmake-build-debug/bin/`, just change `main` :
```c++
int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub, "/../../input/");
}
```
then create the corresponding input files in `input/` .  `test2.cpp` in top-level directory is an example, and note that the  command `target_compile_definitions(test2 PRIVATE -DLOCAL)` in `CMakeLists.txt`.  
