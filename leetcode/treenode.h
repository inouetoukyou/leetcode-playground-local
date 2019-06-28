#ifndef OJ_TREENODE_H
#define OJ_TREENODE_H

#include <string>
#include <vector>
namespace ymh {
template<class T>
struct GenericTreeNode {
    T val;
    GenericTreeNode *left;
    GenericTreeNode *right;

    GenericTreeNode(T x);

    static GenericTreeNode *stringToTreeNode(std::string input);

    static std::vector<T> preorderTraverse(GenericTreeNode *root);

    static std::vector<T> inorderTraverse(GenericTreeNode *root);

    static std::vector<T> postorderTraverse(GenericTreeNode *root);
};
}
#endif //OJ_TREENODE_H
