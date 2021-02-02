# Solutions  
[English Version](README.md)
## 简介
&emsp;&emsp;这个文件夹包含了LeetCode的一些题目的答案。  
[LeetCode 答案索引](https://ytlw.github.io/leetcode)
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
