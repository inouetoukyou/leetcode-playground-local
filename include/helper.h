//
// Created by Minghang Yang on 2019-07-12.
//

#ifndef OJ_HELPER_H
#define OJ_HELPER_H

#include <fstream>
#include <iostream>
#include "../tools/vectortool"
#include "../leetcode_structs/listnode"
#include "../leetcode_structs/treenode"
#include "../leetcode_structs/graphnode"
#include "../leetcode_structs/point.h"

std::ifstream getIfstream(std:: string source) {
    return std::ifstream(source);
}
template <class T = int>
std::vector<T> getVector(std::string &input, char delim = ',') {
    return ymh::GenericVectorGenerator<T>::getSingleVector(input, delim);
}
template <class T = int>
std::vector<std::vector<T>> getVector2(std::string &input, char delim = ',') {
    return ymh::GenericVectorGenerator<T>::getDoubleVector(input, delim);
}

template <class T = int>
ymh::GenericListNode<T>* getList(std::string &input, ymh::OJ_TYPE type = ymh::GenericListNode<T>::LEETCODE, char delim = ',') {
    return ymh::GenericListNode<T>::stringToListNode(input, type, delim);
}

template <class T>
ymh::GenericListNode<T>* setCircle(ymh::GenericListNode<T> *head) {
    return ymh::GenericListNode<T>::setCircle(head);
}

template <class T>
std::vector<T> traverseList(ymh::GenericListNode<T> *head) {
    return ymh::GenericListNode<T>::traverse(head);
}

template <class T = int>
ymh::GenericTreeNode<T> *getTree(std::string &input, char delim = ',') {
    return ymh::GenericTreeNode<T>::stringToTreeNode(input, delim);
}

template <class T>
std::vector<int> preorderTraverseTree(ymh::GenericTreeNode<T> *root) {
    return ymh::GenericTreeNode<T>::preorderTraverse(root);
}

template <class T>
std::vector<int> postorderTraverseTree(ymh::GenericTreeNode<T> *root) {
    return ymh::GenericTreeNode<T>::postorderTraverse(root);
}

template <class T>
std::vector<int> inorderTraverseTree(ymh::GenericTreeNode<T> *root) {
    return ymh::GenericTreeNode<T>::inorderTraverse(root);
}

template <class T>
void outputVector(std::vector<T> &ans, char piv = ' ') {
    for (T &a : ans) {
        std::cout << a << piv;
    }
    std::cout << std::endl;
}

template <class T>
void outputVector2(std::vector<std::vector<T>> ans, char piv = ' ') {
    for (std::vector<T> &an : ans) {
        outputVector(an, piv);
    }
}

int subRoutine(int argc, char *argv[], int(*sub)(), const std::string &relative = "/../../../input/solutions/") {
#ifdef LOCAL
    FILE *fre;
    if (argc == 1) {
        std::string s = argv[0];
        int len = s.size();
        int basePos = len - 1;
        while (basePos >= 0 && s[basePos] != '/') {
            --basePos;
        }
        std::string dirname = s.substr(0, ++basePos);
        std::string basename = s.substr(basePos);
        std::string filePos = dirname + relative + basename + ".in";
        fre = freopen(filePos.c_str(), "r", stdin);
    } else {
        fre = freopen(argv[1], "r", stdin);
    }
#endif
    int rtn = sub();
#ifdef LOCAL
    fclose(fre);
#endif
    return rtn;
}

#endif //OJ_HELPER_H
