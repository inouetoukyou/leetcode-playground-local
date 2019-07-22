//
// Created by Minghang Yang on 2019-07-21.
//

#ifndef OJ_LISTNODE_H
#define OJ_LISTNODE_H
namespace ymh {
typedef int OJ_TYPE;
template <class T>
struct GenericListNode {
    static const OJ_TYPE LEETCODE;
    static const OJ_TYPE LINTCODE;
    T val;
    GenericListNode *next;
    GenericListNode();
    GenericListNode(T val);
    static GenericListNode *stringToListNode(std::string &input, OJ_TYPE type = LEETCODE, char delim = ',');
    static std::vector<T> traverse(GenericListNode *head);
};
}
#endif //OJ_LISTNODE_H
