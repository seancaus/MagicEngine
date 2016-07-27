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
#include "render_system.h"

using namespace std;

namespace Magic{

    class Root :public  Singleton<Root>
    {

    public:

        Root(const string& configFileName,const string& logFileName);
        virtual ~Root();

        RenderWindow* Initialise(const string& windowTitle = "Magic Render Window");
        SceneManager* CreateSceneManager();

        void AddRenderSystem(shared_ptr<RenderSystem> render);
        void SetRenderSystem(shared_ptr<RenderSystem> render);

        bool RenderOneFrame();
        void StartRendering();
        shared_ptr<RenderSystem>GetRenderSystemByName(const string& name);

    protected:

        map<string,shared_ptr<RenderSystem>>    renders_;
        shared_ptr<RenderSystem>                activeRenderer_;

        shared_ptr<RenderWindow>    renderWindow_;
        shared_ptr<LogManager>      logManager_;
    };
}


#endif //MAGICCUBE_ROOT_H
