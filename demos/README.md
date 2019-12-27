## Menus
### demo
1) **big_input.cpp**  
This test is for big input (see that in input/demo/big_input.in). It probably can not feed so large data to terminal by pasting, instead we can use
`cat ../../input/demo/big_input.in|./big_input`.
This test also includes `helper.h`, where the declared function `getVector` and `getVector2` are helpful for  converting `string` to `vector<T>` and `vector<vector<T>>`.
2) **char_doublevector.cpp**  
Test for converting `string` to `vector<vector<char>>`
3) **custom_vector.cpp**  
Test for converting `string` to a custom class.
In this case, the class is
    ```c++
    class Interval {
    public:
        int start, end;
        Interval(int start, int end) {
            this->start = start;
            this->end = end;
        }
    };
    ```
4) **doublevector.cpp**  
Test for converting `string` to `vector<vector<int>>`
5) **file_input.cpp**  
Test for get input from file
6) **string_vector.cpp**  
Test for converting `string` to `string`
7) **test_listnode.cpp**  
Test for converting `string` to `ListNode`
In this case `ListNode` = `GenericListNode<int>`
    ```c++
    template <class T>
    struct GenericListNode {
        ...
        T val;
        GenericListNode *next;
        ...
    }
    ```
8) **test_treenode.cpp**  
Test for converting `string` to `TreeNode`.
In this case `TreeNode` = `GenericTreeNode<int>`
    ```c++
    template<class T>
    struct GenericTreeNode {
        T val;
        GenericTreeNode *left;
        GenericTreeNode *right;
        ...
    }
    ```
