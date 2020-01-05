# Solutions  
[English Version](README.ZH.md)
## Descriptions
这个文件夹包含了LeetCode的一些题目的答案。
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
请在 `Solution` 类里完成你的算法。  
请在 `sub()` 函数里将输入数据转化成对应的数据结构，然后调用 `Solution` 里的方法。
### 输入
程序默认从文件而不是终端读取输入，这样的程序都在文件夹 `input/solutions/`有对应的输入文件。一些特别的题目则没有，比如 *intersection-of-two-linked-lists* 。
