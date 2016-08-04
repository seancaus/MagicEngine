//
// Created by huxf on 2016/7/21.
//

#include <iostream>
#include <GLFW/glfw3.h>
#include "root.h"
#include "../Plugin/RenderSystem/GL/gl_render_system.h"

using  namespace std;

namespace Magic {

    template<> Root *Singleton<Root>::instance_ = nullptr;

    Root::Root(const string &configFileName, const string &logFileName):
        logManager_(nullptr),
        renderWindow_(nullptr)
    {
        if(!LogManager::GetInstancePtr())
        {
            logManager_ = make_shared<LogManager>();
            logManager_->CreateLog(logFileName);
        }


        auto renderSystem = make_shared<GLRenderSystem>();
        AddRenderSystem(renderSystem);
        SetRenderSystem(renderSystem);
    }

    Root::~Root()
    {
    }

    RenderWindow *Root::Initialise(const string& windowTitle)
    {
        renderWindow_ = activeRenderer_->Initialise(windowTitle);
        return renderWindow_.get();
    }

    SceneManager *Root::CreateSceneManager()
    {
        return nullptr;
    }

    void Root::StartRendering()
    {
        while(true)
        {
            //todo event
            glfwPollEvents();


            if( !RenderOneFrame() ) break;
        }
    }

    bool Root::RenderOneFrame()
    {
        UpdateAllRenderTargets();

        return true;
    }

    bool Root::UpdateAllRenderTargets()
    {
        activeRenderer_->UpdateAllRenderTargets(false);

        return true;
    }

    void Root::Shutdown()
    {

    }

    void Root::AddRenderSystem(shared_ptr<RenderSystem> render)
    {
        renders_.insert(map<string,shared_ptr<RenderSystem>>::value_type(render->GetName(),render));
    }

    void Root::SetRenderSystem(shared_ptr<RenderSystem> render)
    {
        activeRenderer_ = render;
    }

    shared_ptr<RenderSystem> Root::GetRenderSystemByName(const string &name)
    {
        return renders_[name];
    }

}