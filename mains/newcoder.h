// Created by yangminghang on 2021/1/3.

#ifndef OJ_NEWCODER_H
#define OJ_NEWCODER_H
#include <helper.h>
#include <treenode_int.h>
#include <listnode_int.h>
int subRoutine(int argc, char *argv[], int(*sub)()) {
    return subRoutine(argc, argv, sub, "../../../mains/");
}
#endif //OJ_NEWCODER_H
