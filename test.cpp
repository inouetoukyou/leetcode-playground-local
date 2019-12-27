#include <helper.h>
using namespace std;

using T = int;
using ListNode = ymh::GenericListNode<T>;
using TreeNode = ymh::GenericTreeNode<T>;
string fileSource = "../../input/test.in";

class Solution {

};

int main() {
    // test ListNode
    cout << "test ListNode:\n";
    cout << "traverse ListNode:\n\t";
    string inputList = "[3,2,0,-4]";
    ListNode *head = getList(inputList);
    vector<int> vList = traverseList(head);
    outputVector(vList);
    cout << "\n";

    // test TreeNode
    cout << "test TreeNode:\n";
    cout << "inorder traverse TreeNode:\n\t";
    string inputTree = "[1, null, 2  ,  4,7, 9]";
    TreeNode *root = getTree(inputTree);
    vector<int> vTree = inorderTraverseTree(root);
    outputVector(vTree);
    cout << "\n";

    // test vector
    cout << "test vector:\n";
    cout << "output vector:\n\t";
    string inputVector = "[9,1,2,3,9]";
    vector<int> v = getVector(inputVector);
    outputVector(v);
    cout << "\n";

    // using file to handle big input
    cout << "using file to handle big input:\n";
    ifstream in = getIfstream(fileSource);
    if (in) {
        string firstLine;
        getline(in, firstLine);
        cout << "firstLine of file:\n\t";
        cout << firstLine << endl;
        in.close();
    }
    cout << "\n";

    // test string vector
    cout << "test string vector:\n";
    string input = "[\"/*Test program */\",\"int main()\",\"{ \",\"  // variable declaration \",\"int a, b, c;\",\"/* This is a test\",\"   multiline  \",\"   comment for \",\"   testing */\",\"a = b + c;\",\"}\"]";
    vector<string> source = getVector<string>(input);
    outputVector(source, '\n');
    return 0;
}