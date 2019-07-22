#include "helper.h"
using namespace std;

using T = int;
using ListNode = ymh::GenericListNode<T>;
using TreeNode = ymh::GenericTreeNode<T>;
string fileSource = "../../test_input.txt";

class Solution {

};

int main() {
    // test ListNode
    cout << "traverse ListNode:\n\t";
    string inputList = "[3,2,0,-4]";
    ListNode *head = getList(inputList);
    vector<int> vList = traverseList(head);
    outputVector(vList);

    // test TreeNode
    cout << "inorder traverse TreeNode:\n\t";
    string inputTree = "[1, null, 2  ,  4,7, 9]";
    TreeNode *root = getTree(inputTree);
    vector<int> vTree = inorderTraverseTree(root);
    outputVector(vTree);

    // test vector
    cout << "output vector:\n\t";
    string inputVector = "[9,1,2,3,9]";
    vector<int> v = getVector(inputVector);
    outputVector(v);

    // using file to handle big input
    ifstream in = getIfstream(fileSource);
    if (in) {
        string firstLine;
        getline(in, firstLine);
        cout << "firstLine of file:\n\t";
        cout << firstLine << endl;
        in.close();
    }
    return 0;
}