//
// Created by Minghang Yang on 2019-07-12.
//

#ifndef OJ_HELPER_H
#define OJ_HELPER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "leetcode/vectortool"
#include "leetcode/listnode"
#include "leetcode/treenode"
#include "leetcode/graphnode"
#include "leetcode/point.h"

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

#endif //OJ_HELPER_H
