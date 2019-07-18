//
// Created by Minghang Yang on 2019-07-12.
//

#ifndef OJ_VECTOR_HELPER_H
#define OJ_VECTOR_HELPER_H

#include <vector>
#include <string>
#include <iostream>
#include "../leetcode/treenode"
#include "../leetcode/vectortool"
template <class T = int>
std::vector<T> getVector(std::string &input, char delim = ',') {
    return ymh::GenericVectorGenerator<T>::getSingleVector(input, delim);
}
template <class T = int>
std::vector<std::vector<T>> getVector2(std::string &input, char delim = ',') {
    return ymh::GenericVectorGenerator<T>::getDoubleVector(input, delim);
}

template <class T>
void outputVector(std::vector<T> &ans) {
    for (T &a : ans) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
}

template <class T>
void outputVector2(std::vector<std::vector<T>> ans) {
    for (std::vector<T> &an : ans) {
        for (T &a : an) {
            std::cout << a << " ";
        }
        std::cout << std::endl;
    }
}

#endif //OJ_VECTOR_HELPER_H
