//
// Created by Minghang Yang on 2020/2/4.
// thanks leetcode for function prettyPrintTree
//

#ifndef OJ_TREENODE_INT_H
#define OJ_TREENODE_INT_H
using TreeNode = ymh::GenericTreeNode<int>;
#include <string>
void prettyPrintTree(TreeNode * node, const std::string& prefix = "", bool isLeft = true) {
    if (node == nullptr) {
        std::cout << "Empty tree";
        return;
    }

    if(node->right) {
        prettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }

    std::cout << prefix + (isLeft ? "└── " : "┌── ") + std::to_string(node->val) + "\n";

    if (node->left) {
        prettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
    }
}
#endif //OJ_TREENODE_INT_H
