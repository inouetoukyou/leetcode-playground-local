// Created by yangminghang on 2021/1/3.

#ifndef OJ_LEETCODE_H
#define OJ_LEETCODE_H
#include <helper.h>
#include <treenode_int.h>
#include <listnode_int.h>
int subRoutine(int argc, char *argv[], int(*sub)()) {
    return subRoutine(argc, argv, sub, "../../../../solutions/leetcode/");
}
#endif //OJ_LEETCODE_H
