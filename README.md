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
