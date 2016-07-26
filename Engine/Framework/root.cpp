//
// Created by huxf on 2016/7/21.
//

#include <iostream>
#include "root.h"

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
    }

    Root::~Root()
    {
    }

    RenderWindow *Root::initialise(const string& windowTitle) {
        return nullptr;
    }


    SceneManager *Root::createSceneManager() {
        return nullptr;
    }

    void Root::startRendering() {

    }


}