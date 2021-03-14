// Created by yangminghang on 2021/3/14.

// Given a binary tree, find the lowest common ancestor
// (LCA) of two given nodes in the tree.
//
// According to the definition of LCA on Wikipedia:
// “The lowest common ancestor is defined between two nodes
// p and q as the lowest node in T that has both p and q as
// descendants (where we allow a node to be a descendant of itself).”

#include "leetcode.h"

using namespace std;

class Solution {
public:
    TreeNode *find(TreeNode *root,int v) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val == v) {
            return root;
        }
        auto ans = find(root->left, v);
        if (ans != nullptr) {
            return ans;
        }
        return find(root->right, v);
    }
private:
    bool hasChild(TreeNode *root, TreeNode *p, vector<TreeNode*> &path) {
        if (root == nullptr) {
            return false;
        }
        path.push_back(root);
        if (root == p) {
            return true;
        }
        if (hasChild(root->left, p, path)){
            return true;
        }
        while (!path.empty() && path.back() != root) {
            path.pop_back();
        }
        return hasChild(root->right, p, path);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }
        vector<TreeNode*> lpath;
        hasChild(root, p, lpath);
        vector<TreeNode*> rpath;
        hasChild(root, q, rpath);
        int n1 = lpath.size(), n2 = rpath.size();
        TreeNode *ans = root;
        for (int i = 1; i < n1 && i < n2; ++i) {
            if (lpath[i] != rpath[i]) {
                return ans;
            }
            ans = lpath[i];
        }
        return ans;
    }
};

int sub() {
    Solution solution;
    string s;
    while (getline(cin, s)) {
        if (s == "") {
            continue;
        }
        auto root = getTree(s);
        int p, q;
        cin >> p >> q;
        cout << solution.lowestCommonAncestor(root, solution.find(root, p), solution.find(root, q))->val << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
