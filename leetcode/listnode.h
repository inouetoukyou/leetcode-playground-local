//
// Created by Minghang Yang on 2019-07-21.
//

#ifndef OJ_LISTNODE_H
#define OJ_LISTNODE_H
namespace ymh {
template <class T>
struct GenericListNode {
    T val;
    GenericListNode *next;
    GenericListNode(T val);
};
}
#endif //OJ_LISTNODE_H
