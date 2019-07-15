//
// Created by Minghang Yang on 2019-07-12.
//

#ifndef OJ_HELPER_H
#define OJ_HELPER_H

#include <vector>
#include <string>
#include <iostream>
#include "leetcode/treenode"
#include "leetcode/vectortool"
template <class T = int>
std::vector<T> getVector(std::string &input) {
    return ymh::GenericVectorGenerator<T>::getSingleVector(input);
}
template <class T = int>
std::vector<std::vector<T>> getDVector(std::string &input) {
    return ymh::GenericVectorGenerator<T>::getDoubleVector(input);
}
template <class T>
void output_vector2(std::vector<std::vector<T>> ans) {
    for (std::vector<T> &an : ans) {
        for (T &a : an) {
            std::cout << a << " ";
        }
        std::cout << std::endl;
    }
}
template <class T>
void output_vector(std::vector<T> &ans) {
    for (T &a : ans) {
        std::cout << a << " ";
    }
    std::cout << std::endl;
}
#endif //OJ_HELPER_H
