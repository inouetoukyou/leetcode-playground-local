# Solutions  
[English Version](README.md)
## 简介
&emsp;&emsp;这个文件夹包含了LeetCode的一些题目的答案。  
[LeetCode 答案索引](https://ytlw.github.io/leetcode/?version=latest)
## 使用方式
### 头文件包含
```c++
#include <helper.h>
#include <map> // 如果需要
#include <set> // 如果需要
using namespace std;
```
### 使用链表节点ListNode
```c++
using T = int;
ListNode = ymh::GenericListNode<T>;
```
### 代码模版
```c++
class Solution {}
int sub() {
    Solution solution;
    string s;
    while (getline(cin, s)) {

    }
}
int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
```
&emsp;&emsp; `subRoutine` 的函数实现请参照 `include/helper.h`  
&emsp;&emsp;请在 `Solution` 类里完成你的算法。  
&emsp;&emsp;请在 `sub()` 函数里将输入数据转化成对应的数据结构，然后调用 `Solution` 里的方法。
### 输入
&emsp;&emsp;程序默认从文件而不是终端读取输入，这样的程序都在文件夹 `input/solutions/`有对应的输入文件。一些特别的题目则没有，比如 *intersection-of-two-linked-lists* 。如果使用该模板，在 `solutions` 中创建源文件后，也要在 `input/solutions/` 中创建对应的输入文件。  
&emsp;&emsp;因为默认的可执行文件（基于CLion IDE）位于 `cmake-build-debug/bin/solutions/` 中，所以 `subRoutine` 函数的第四个参数默认值为 `const char* relative = "/../../../input/solutions/"`。如果你想在顶层的源文件中使用此模板，默认地，顶层源文件对应的可执行文件位于 `cmake-build-debug/bin/` 中，因此可修改 `main` 函数为：
```c++
int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub, "/../../input/");
}
```
然后在 `input/` 中创建对应的输入文件。可以参照位于顶层目录的 `test2.cpp` 的例子，并注意 `CMakeLists.txt` 里的 `target_compile_definitions(test2 PRIVATE -DLOCAL)`。  