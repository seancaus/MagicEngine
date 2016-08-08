//
// Created by huxf on 2016/8/4.
//

#ifndef MAGIC_RENDERABLE_H
#define MAGIC_RENDERABLE_H

#include <memory>

using namespace std;

namespace Magic
{

    class RenderOperation;

    class Renderable {

    public:

        Renderable() ;
        virtual ~Renderable();

        void GetRenderOperation(shared_ptr<RenderOperation>& ro);

    protected:


    };
}


#endif //MAGIC_RENDERABLE_H
