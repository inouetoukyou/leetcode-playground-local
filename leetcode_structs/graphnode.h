//
// Created by Minghang Yang on 2019-07-23.
//

#ifndef OJ_GRAPHNODE_H
#define OJ_GRAPHNODE_H
namespace ymh{
template <class T>
struct GenericDirectedGraphNode {
    T label;
    std::vector<GenericDirectedGraphNode*> neighbors;
    GenericDirectedGraphNode(T label);
};

template <class T>
struct GenericUndirectedGraphNode {
    T label;
    std::vector<GenericUndirectedGraphNode*> neighbors;
    GenericUndirectedGraphNode(T label);
};
}
#endif //OJ_GRAPHNODE_H
