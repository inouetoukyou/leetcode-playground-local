#ifndef OJ_TREENODE_H
#define OJ_TREENODE_H

#include <string>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x);
    static TreeNode* stringToTreeNode(std::string input);
};

#endif //OJ_TREENODE_H
