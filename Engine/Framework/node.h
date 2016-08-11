//
// Created by huxf on 2016/8/4.
//

#ifndef MAGIC_NODE_H
#define MAGIC_NODE_H

#include <map>
#include <memory>
#include <string>

using namespace std;

namespace Magic
{
    class Node;

    typedef map<string, shared_ptr<Node>>  ChildNodeMap;

    class Node
    {

    public:

        Node();
        virtual ~Node();

    protected:

        Node*           parent_;
        ChildNodeMap    children_;

    };

}
#endif //MAGIC_NODE_H
