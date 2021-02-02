# Solutions  
[中文版](README.ZH.md)
## Descriptions
&emsp;This directory contains some solutions of LeetCode.  
[LeetCode Solutions Indices](https://ytlw.github.io/leetcode)
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
int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
```
&emsp;Please refer to `include/helerp.h` for details of function `subRoutine`  
&emsp;Please complete the algorithm in class `Solution`.  
&emsp;In function `sub()`, please convert the input to data structure you want, then call the function in `Solution`.
