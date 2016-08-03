//
// Created by huxf on 2016/7/19.
//

#ifndef MAGICCUBE_APPLICATION_H
#define MAGICCUBE_APPLICATION_H

#include <memory>

#include "object.h"
#include "render_window.h"

using namespace std;

namespace Magic {
    class Application : public Object {

    public:
        Application();

        virtual ~Application();

        int Run();

        void Close();

    protected:


    };
}
#endif //MAGICCUBE_APPLICATION_H
