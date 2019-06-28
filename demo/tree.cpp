//
// Created by Minghang Yang on 2019-06-29.
//
#include <vector>
#include <iostream>
#include "../leetcode/treenode"

using namespace std;
using namespace ymh;
using T = int;
using TreeNode = GenericTreeNode<T>;

int main() {
    string tree_string;
    getline(cin, tree_string);
    TreeNode *root = TreeNode::stringToTreeNode(tree_string);
    vector<T> ans = TreeNode::preorderTraverse(root);
    for (int & an : ans) {
        cout << an << " ";
    }
    cout << endl;
    return 0;
}