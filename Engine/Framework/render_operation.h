//
// Created by huxf on 2016/8/5.
//

#ifndef MAGIC_RENDER_OPERATION_H
#define MAGIC_RENDER_OPERATION_H

#include <memory>

using namespace std;

namespace magic
{

    class VertexData;
    class IndexData;

    class RenderOperation
    {
    public:

        enum OperationType
        {

        };

        RenderOperation() ;
        virtual ~RenderOperation();

    protected:

        OperationType   operationType_;
        shared_ptr<VertexData>  vertexData_;
        shared_ptr<IndexData>   indexData_;
        bool            useIndexes_;
        unsigned int    numberOfInstances_;
    };

}

#endif //MAGIC_RENDER_OPERATION_H
