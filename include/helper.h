//
// Created by Minghang Yang on 2019-07-12.
//

#ifndef OJ_HELPER_H
#define OJ_HELPER_H

#include <fstream>
#include <iostream>
#include <libgen.h>
#include <cstring>
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

template <class T>
void outputVector(std::vector<T> &ans, char piv = ' ') {
    for (T &a : ans) {
        std::cout << a << piv;
    }
    std::cout << std::endl;
}

template <class T>
void outputVector(std::vector<T> &&ans, char piv = ' ') {
    outputVector(ans, piv);
}

template <class T>
void outputVector2(std::vector<std::vector<T>> &ans, char piv = ' ') {
    for (std::vector<T> &an : ans) {
        outputVector(an, piv);
    }
}

template <class T>
void outputVector2(std::vector<std::vector<T>> &&ans, char piv = ' ') {
    outputVector2(ans, piv);
}
template <class T = int>
ymh::GenericListNode<T>* getList(std::string &input, ymh::OJ_TYPE type = ymh::GenericListNode<T>::LEETCODE, char delim = ',') {
    return ymh::GenericListNode<T>::stringToListNode(input, type, delim);
}

template <class T = int>
ymh::GenericListNode<T>* getListLintCode(std::string &input) {
    return getList(input, ymh::GenericListNode<T>::LINTCODE, '>');
}

#ifdef OJ_LISTNODE_CIRCLE
template <class T>
ymh::GenericListNode<T>* setCircle(ymh::GenericListNode<T> *head) {
    return ymh::GenericListNode<T>::setCircle(head);
}
#endif

template <class T>
std::vector<T> traverseList(ymh::GenericListNode<T> *head) {
    return ymh::GenericListNode<T>::traverse(head);
}

#ifdef OJ_LISTNODE_CIRCLE
template <class T>
std::vector<T> traverseCyclicList(ymh::GenericListNode<T> *head) {
    return ymh::GenericListNode<T>::traverseCyclic(head);
}
#endif

template <class T>
void outputList(ymh::GenericListNode<T> *head) {
    outputVector(traverseList(head));
}

#ifdef OJ_LISTNODE_CIRCLE
template <class T>
void outputCyclicList(ymh::GenericListNode<T> *head) {
    outputVector(traverseCyclicList(head));
}
#endif


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

int subRoutine(int argc, char *argv[], int(*sub)(), const char* relative = "/../../../input/solutions/") {
#ifdef LOCAL
    FILE *fre;
    if (argc == 1) {
        int lenArgv0 = strlen(argv[0]);
        char path1[lenArgv0];
        strcpy(path1, argv[0]);
        char path2[lenArgv0];
        strcpy(path2, argv[0]);

        char *baseName = basename(path1);
        char *dirName = dirname(path2);
        int lenDirName = strlen(dirName);
        int lenRelative = strlen(relative);
        int lenBaseName = strlen(baseName);
        if (lenBaseName > 4 && baseName[lenBaseName - 1] == 'e' &&
        baseName[lenBaseName - 2] == 'x' && baseName[lenBaseName - 3] == 'e' &&
        baseName[lenBaseName - 4] == '.') {
            baseName[lenBaseName - 4] = '\0';
            lenBaseName -= 4;
        }
        int len = lenDirName + lenRelative + lenBaseName + 4;
        char filePath[len];
        strcpy(filePath, dirName);
        strcat(filePath, relative);
        strcat(filePath, baseName);
        strcat(filePath, ".in");
        fre = freopen(filePath, "r", stdin);
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
