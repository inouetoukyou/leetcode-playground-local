#include "custom.h"

using namespace std;

class Solution {
public:
    static vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        ans.reserve(16);
        std::queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            int n = queue.size();
            vector<int> item(n);
            for (int i = 0; i < n; i++) {
                TreeNode *node = queue.front();
                queue.pop();
                item[i] = node->val;
                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }
            }
            ans.push_back(item);
        }
        return ans;
    }
};

int sub() {
    string s;
    while (getline(cin, s)) {
        TreeNode *root = getTree(s);
        prettyPrintTree(root);
        outputVector2(Solution::levelOrder(root));
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub, subroutineRelative);
}
