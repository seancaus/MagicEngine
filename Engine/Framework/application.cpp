//
// Created by huxf on 2016/7/19.
//
#include <iostream>

#include "application.h"
#include "root.h"
#include "scene_node.h"
#include "entity.h"

using namespace std;

namespace Magic {

    static float WIDTH = 640;
    static float HEIGHT = 480;


    Application::Application() {

    }
    //-----------------------------------------------------------------------
    Application::~Application() {

    }
    //-----------------------------------------------------------------------
    int Application::Run()
    {
        Magic::Root *root = new Magic::Root("config.cfg", "magic.log");
        RenderWindow *renderWindow = root->Initialise();

        sceneManager_ = root->CreateSceneManager();
        Camera* camera = sceneManager_->createCamera("asd");
        camera->lookAt(0,0,0);

        renderWindow->addViewport(camera);

        CreateScene();
        root->StartRendering();

        return 0;
    }
    //-----------------------------------------------------------------------
    void Application::CreateScene()
    {
        auto entity = sceneManager_->createEntity("");
        auto node = sceneManager_->getRootSceneNode()->createChild("ddddd",Vector3(.0,.0,.0));
        node->attachObject(entity);
    }
    //-----------------------------------------------------------------------
    void Application::Close()
    {

    }
    //-----------------------------------------------------------------------
}