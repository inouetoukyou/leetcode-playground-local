//
// Created by Minghang Yang on 2019-06-29.
//
#include <iostream>
#include "../leetcode_structs/treenode"

using namespace std;
using namespace ymh;
using T = int;
using TreeNode = GenericTreeNode<T>;

int main() {
    string tree_string;
//    getline(cin, tree_string);
    tree_string = "[1, null, 2  ,  4,7, 9]";
    TreeNode *root = TreeNode::stringToTreeNode(tree_string);
    vector<T> ans = TreeNode::preorderTraverse(root);
    for (int & an : ans) {
        cout << an << " ";
    }
    cout << endl;
    /* output
     * 1 2 4 9 7*/
    return 0;
}