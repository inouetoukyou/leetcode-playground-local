#ifndef OJ_TREENODE_H
#define OJ_TREENODE_H

#include <string>
#include <vector>
namespace ymh {
template<class T>
struct GenericTreeNode {
    T val;
    GenericTreeNode *left, *right;

    GenericTreeNode(T t);
};

template<class T, class TreeNode>
struct TreeNodeFactory {
    static TreeNode *stringToTreeNode(std::string &input, char delim = ',');

    static std::vector<T> preorderTraverse(TreeNode *root);

    static std::vector<T> inorderTraverse(TreeNode *root);

    static std::vector<T> postorderTraverse(TreeNode *root);

    static void deleteTree(TreeNode *root);
};
}
#endif //OJ_TREENODE_H
