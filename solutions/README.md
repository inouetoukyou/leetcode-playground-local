# Solutions  
[中文版](README.ZH.md)
## Descriptions
This directory contains some solutions of LeetCode.
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
Please complete the algorithm in class `Solution`.  
In function `sub()`, please convert the input to data structure you want, then call the function in `Solution`.
### input
By default, a program will get input from files not terminal. Such source files have a corresponding input files in directory `input/solutions/`.  Some special program will not, for example *intersection-of-two-linked-lists* .
