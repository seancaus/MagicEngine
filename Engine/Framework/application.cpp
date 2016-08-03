//
// Created by huxf on 2016/7/19.
//
#include <iostream>
#include <GL/glew.h>
#include "application.h"
#include "../../Game/cube_game_mode.h"
#include "root.h"
#include "singleton.h"

using namespace std;

namespace Magic {

    static float WIDTH = 640;
    static float HEIGHT = 480;


    Application::Application() {

    }

    Application::~Application() {

    }

    int Application::Run() {
        Magic::Root *root = new Magic::Root("config.cfg", "magic.log");
        RenderWindow *renderWindow = root->Initialise();

//    SceneManager* sceneManager = root->createSceneManager();
//    Camera* camera = sceneManager->CreateCamera("asd");
//    camera->LookAt();
//
//    renderWindow->AddViewport(camera);

        root->StartRendering();
//    while( root->RenderOneFrame() )
//    {
//
//    }


        return 0;
    }

    void Application::Close() {

    }
}