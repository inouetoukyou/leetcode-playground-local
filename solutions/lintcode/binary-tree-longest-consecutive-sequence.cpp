#include <helper.h>
#include <treenode_int.h>
#include "subroutine_relative.h"

using namespace std;

class Solution {
private:
    int longestConsecutiveHelper(TreeNode *root, int &ans) {
        if (root == nullptr) {
            return 0;
        }
        int t1 = longestConsecutiveHelper(root->left, ans);
        int t2 = longestConsecutiveHelper(root->right, ans);
        if (root->left == nullptr || root->left->val - 1 == root->val) {
            ++t1;
        } else {
            t1 = 1;
        }
        if (root->right == nullptr || root->right->val - 1 == root->val) {
            ++t2;
        } else {
            t2 = 1;
        }
        if (ans < t1) {
            ans = t1;
        }
        if (ans < t2) {
            ans = t2;
        }
        return t1 > t2 ? t1 : t2;
    }
public:
    /**
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */
    int longestConsecutive(TreeNode * root) {
        int ans = 0;
        longestConsecutiveHelper(root, ans);
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
    return subRoutine(argc, argv, sub, subroutineRelative);
}
