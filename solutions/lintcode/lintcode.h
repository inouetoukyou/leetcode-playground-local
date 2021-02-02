// Created by Minghang Yang on 2021/1/23.

//
#ifndef OJ_LINTCODE_H
#define OJ_LINTCODE_H
#include <helper.h>
#include <treenode_int.h>
#include <listnode_int.h>
int subRoutine(int argc, char *argv[], int(*sub)()) {
    return subRoutine(argc, argv, sub, "../../../../solutions/lintcode/");
}
#endif //OJ_LINTCODE_H
