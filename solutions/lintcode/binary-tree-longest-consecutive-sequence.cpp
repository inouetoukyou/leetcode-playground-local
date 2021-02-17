#include "lintcode.h"

using namespace std;

class Solution {
private:
    int helper(TreeNode *root, int &ans) {
        if (root == nullptr) {
            return 0;
        }
        auto left = helper(root->left, ans);
        auto right = helper(root->right, ans);
        if (root->left != nullptr && root->val + 1 == root->left->val) {
            ++left;
        } else {
            left = 1;
        }
        if (root->right != nullptr && root->val + 1 == root->right->val) {
            ++right;
        } else {
            right = 1;
        }
        int v = max(left, right);
        ans = max(ans, v);
        return v;
    }
public:
    /**
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    int longestConsecutive(TreeNode * root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};

int sub() {
    string s;
    Solution solution;
    while (getline(cin, s)) {
        TreeNode *root = getTree(s);
        cout << solution.longestConsecutive(root) << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
