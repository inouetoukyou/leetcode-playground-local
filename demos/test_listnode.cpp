//
// Created by Minghang Yang on 2019-07-22.
//

#include "../helper.h"

using namespace std;
using T = int;
using ListNode = ymh::GenericListNode<T>;
#define LINTCODE ListNode::LINTCODE
int main() {
    string input1 = "5-> 1 -> 3->4";
    ListNode *head1 = getList(input1, LINTCODE, '>');
    string input2 = "5->1 -> 4->9->543->null";
    ListNode *head2 = getList(input2, LINTCODE, '>');
    string input3 = "[4,2, 1 ,  3]";
    ListNode *head3 = getList(input3);
    vector<int> ans1 = traverseList(head1);
    outputVector(ans1);
    vector<int> ans2 = traverseList(head2);
    outputVector(ans2);
    vector<int> ans3 = traverseList(head3);
    outputVector(ans3);
    return 0;
}