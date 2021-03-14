// Created by yangminghang on 2021/3/14.

// Given a binary tree, find the lowest common ancestor
// (LCA) of two given nodes in the tree.
//
// According to the definition of LCA on Wikipedia:
// “The lowest common ancestor is defined between two nodes
// p and q as the lowest node in T that has both p and q as
// descendants (where we allow a node to be a descendant of itself).”

#include "leetcode.h"
#include <unordered_map>
#include <unordered_set>

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

class Solution2 {
private:
    bool helper(TreeNode *root, TreeNode *p, TreeNode *q, TreeNode * &ans) {
        if (root == nullptr) {
            return false;
        }
        int left = helper(root->left, p, q, ans) ? 1 : 0;
        int right = helper(root->right, p, q, ans) ? 1 : 0;
        int mid = 0;
        if (root == p || root == q) {
            mid = 1;
        }
        if (mid + left + right >= 2) {
            ans = root;
        }
        return mid + left + right > 0;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ans = nullptr;
        helper(root, p, q, ans);
        return ans;
    }
};

class Solution3 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // stack for traversing
        stack<TreeNode*> traverse;
        // hash map for parent pointers
        unordered_map<TreeNode*, TreeNode*> parents;
        parents[root] = nullptr;
        traverse.push(root);
        // iterate until we find both the nodes p and q
        while (parents.find(p) == parents.end() || parents.find(q) == parents.end()) {
            auto node = traverse.top();
            traverse.pop();
            // while traversing the tree, keep saving the parent pointers.
            if (node->left != nullptr) {
                traverse.push(node->left);
                parents[node->left] = node;
            }
            if (node->right != nullptr) {
                traverse.push(node->right);
                parents[node->right] = node;
            }
        }
        // ancessors set for node p
        unordered_set<TreeNode*> ancessors;
        // process all ancessors for node p using parent pointers.
        while (p != nullptr) {
            ancessors.insert(p);
            p = parents[p];
        }
        // The first ancessor of q which appears in p's ancessor set is their
        // lowest common ancessor.
        while (ancessors.find(q) == ancessors.end()) {
            q = parents[q];
        }
        return q;
    }
};

int sub() {
    Solution solution;
    Solution2 solution2;
    Solution3 solution3;
    string s;
    while (getline(cin, s)) {
        if (s == "") {
            continue;
        }
        auto root = getTree(s);
        int pv, qv;
        cin >> pv >> qv;
        TreeNode *p = solution.find(root, pv);
        TreeNode *q = solution.find(root, qv);
        cout << solution.lowestCommonAncestor(root, p, q)->val << " ";
        cout << solution2.lowestCommonAncestor(root, p, q)->val << " ";
        cout << solution3.lowestCommonAncestor(root, p, q)->val << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
