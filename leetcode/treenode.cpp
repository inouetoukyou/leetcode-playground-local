#include "treenode.h"
#include "stringtool.h"
#include <cstdio>
#include <sstream>
#include <queue>
TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

/*
 construct a Tree from string
 {1, #, 2, 3}
 [1,null,2, 3] --> 1
                  / \
                    2
                   / \
                   3
*/
TreeNode* TreeNode::stringToTreeNode(std::string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (input.empty()) {
        return nullptr;
    }

    std::string item;
    std::stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    auto root = new TreeNode(stoi(item));
    std::queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null" || item != "#") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}