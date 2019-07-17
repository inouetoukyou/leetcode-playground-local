# LeetCode Playground Local
## Description
This is an input helper for LeetCode. When we solve the problems in LeetCode, we can only see a Solution class, but this project can help we convert `string` to a specific data type, so we can debug our code in local IDE. Besides, it is generic, in other word, it can convert `string` to `vector<T>`, here `T` can be `int`, `double` and other basic types, it can even adapt to a custom class if we write a specific `stringToValue` function for this class. It also supports `TreeNode`.

## Usage 
`$ mv CMakeLists.txt.copy CMakeLists.txt`  
`$ mkdir build`  
`$ cd build`  
`$ cmake ..`  
`$ make`  
`$ cd bin`  
now you can see the demos.

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
5) **tree.cpp**  
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

