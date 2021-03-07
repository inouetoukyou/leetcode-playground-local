// Created by yangminghang on 2021/3/7.

// Given a binary tree
//
// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node.
// If there is no next right node, the next pointer should be
// set to NULL.
//
// Initially, all next pointers are set to NULL.
//
// Follow up:
// You may only use constant extra space.
// Recursive approach is fine, you may assume implicit stack
// space does not count as extra space for this problem.

#include "leetcode.h"
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

void printNode(Node *root) {
    if (root == nullptr) {
        cout << "[]" << endl;
        return;
    }
    cout << "[";
    cout << root->val << ",#";
    Node *next = nullptr;
    if (root->left != nullptr) {
        next = root->left;
    } else if (root->right != nullptr) {
        next = root->right;
    }
    Node *cur = next;
    next = nullptr;
    while (cur != nullptr || next != nullptr) {
        if (cur != nullptr) {
            cout << "," << cur->val;
            if (next == nullptr) {
                if (cur->left != nullptr) {
                    next = cur->left;
                } else if (cur->right != nullptr) {
                    next = cur->right;
                }
            }
            cur = cur->next;
        } else {
            cout << ",#";
            cur = next;
            next = nullptr;
        }
    }
    cout << ",#]" << endl;
}

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        queue<Node*> q;
        root->next = nullptr;
        if (root->left != nullptr) {
            q.push(root->left);
        }
        if (root->right != nullptr) {
            q.push(root->right);
        }
        while (!q.empty()) {
            int n = q.size();
            auto cur = q.front();
            if (cur->left != nullptr) {
                q.push(cur->left);
            }
            if (cur->right != nullptr) {
                q.push(cur->right);
            }
            q.pop();
            for (int i = 1; i < n; ++i) {
                auto next = q.front();
                cur->next = next;
                if (next->left != nullptr) {
                    q.push(next->left);
                }
                if (next->right != nullptr) {
                    q.push(next->right);
                }
                cur = next;
                q.pop();
            }
            cur->next = nullptr;
        }
        return root;
    }

    Node* connect2(Node* root) {
        Node *head = nullptr; //head of the next level
        Node *prev = nullptr; //the leading node on the next level
        Node *cur = root;  //current node of current level

        while (cur != nullptr) {
            while (cur != nullptr) { //iterate on the current level
                //left child
                if (cur->left != nullptr) {
                    if (prev != nullptr) {
                        prev->next = cur->left;
                    } else {
                        head = cur->left;
                    }
                    prev = cur->left;
                }
                //right child
                if (cur->right != nullptr) {
                    if (prev != nullptr) {
                        prev->next = cur->right;
                    } else {
                        head = cur->right;
                    }
                    prev = cur->right;
                }
                //move to next node
                cur = cur->next;
            }

            //move to next level
            cur = head;
            head = nullptr;
            prev = nullptr;
        }
        return root;
    }

    Node *connect3(Node *root) {
        if (root == nullptr) {
            return nullptr;
        }
        Node *curP = root;
        Node nextDummyHead = Node(0);
        Node *p = &nextDummyHead;
        while (curP != nullptr) {
            if (curP->left != nullptr) {
                p->next = curP->left;
                p = p->next;
            }
            if (curP->right != nullptr) {
                p->next = curP->right;
                p = p->next;
            }
            if (curP->next != nullptr) {
                curP = curP->next;
            } else {
                curP = nextDummyHead.next;
                nextDummyHead.next = nullptr;
                p = &nextDummyHead;
            }
        }
        return root;
    }

    Node* connect4(Node *root) {
        if (root == nullptr) {
            return nullptr;
        }
        Node dummy = Node(0);
        Node *p = &dummy;
        Node *head = root;
        while (head != nullptr) { //if the head of the traverse layer is not null, then traverse that layer...
            Node *node = head;
            while (node != nullptr) {
                if (node->left != nullptr) {
                    p->next = node->left;
                    p = p->next;
                }
                if (node->right != nullptr) {
                    p->next = node->right;
                    p = p->next;
                }
                node = node->next;
            }
            //after traversed to the end of current layer, move to the next layer
            head = dummy.next;
            dummy.next = nullptr;
            p = &dummy;
        }
        return root;
    }

    Node* connect5(Node *root) {
        Node *now = root, *tail = nullptr, *head = nullptr;
        while(now != nullptr) {
            if (now->left != nullptr) {
                if (tail != nullptr) {
                    tail->next = now->left;
                    tail = tail->next;
                } else {
                    head = now->left;
                    tail = now->left;
                }
            }
            if (now->right != nullptr) {
                if (tail != nullptr) {
                    tail->next = now->right;
                    tail = tail->next;
                } else {
                    head = now->right;
                    tail = now->right;
                }
            }
            now = now->next;
            if(now == nullptr) {
                now = head;
                head = nullptr;
                tail = nullptr;
            }
        }
        return root;
    }
};

int sub() {
    Solution solution;
    string s;
    while (getline(cin, s)) {
        if (s == "") {
            break;
        }
        Node *root = getTree<int, Node>(s);
        printNode(solution.connect(root));
        deleteTree<int, Node>(root);

        root = getTree<int, Node>(s);
        printNode(solution.connect2(root));
        deleteTree<int, Node>(root);

        root = getTree<int, Node>(s);
        printNode(solution.connect3(root));
        deleteTree<int, Node>(root);

        root = getTree<int, Node>(s);
        printNode(solution.connect4(root));
        deleteTree<int, Node>(root);

        root = getTree<int, Node>(s);
        printNode(solution.connect5(root));
        deleteTree<int, Node>(root);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
