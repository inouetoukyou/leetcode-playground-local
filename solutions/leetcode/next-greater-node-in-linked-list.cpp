//
// Created by Minghang Yang on 2020/1/5.
//

#include <helper.h>
#include "subroutine_relative.h"
using namespace std;
using T = int;
using ListNode = ymh::GenericListNode<T>;
class Solution {
    /* use a stack*/
public:
    static vector<int> nextLargerNodes(ListNode* head) {
        if (head == nullptr) {
            return vector<int>();
        }
        vector<int> v;
        stack<int> stk; // store the indices
        ListNode *p = head;
        int pos = 0;
        while (p) {
            while (!stk.empty() && v[stk.top()] < p->val) {
                v[stk.top()] = p->val;
                stk.pop();
            }
            v.push_back(p->val);
            stk.push(pos++);
            p = p->next;
        }
        while (!stk.empty()) {
            v[stk.top()] = 0;
            stk.pop();
        }
        return v;
    }
};

int sub() {
    string s;
    while (getline(cin, s)) {
        ListNode *head = getList(s);
        vector<int> ans = Solution::nextLargerNodes(head);
        outputVector(ans);
        ListNode::deleteList(head);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub, subroutine_relative);
}
