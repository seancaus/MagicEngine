//
// Created by huxf on 2016/7/21.
//

#ifndef MAGICCUBE_ROOT_H
#define MAGICCUBE_ROOT_H

#include <string>
#include "singleton.h"
#include "render_window.h"
#include "scene_manager.h"
#include "log_manager.h"

using namespace std;

namespace Magic{

    class Root :public  Singleton<Root>
    {

    public:

        Root(const string& configFileName,const string& logFileName);
        virtual ~Root();

        RenderWindow* initialise(const string& windowTitle = "Magic Render Window");
        SceneManager* createSceneManager();

        void startRendering();

    protected:

        shared_ptr<RenderWindow>    renderWindow_;
        shared_ptr<LogManager>      logManager_;

    };
}


#endif //MAGICCUBE_ROOT_H
