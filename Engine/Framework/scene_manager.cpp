//
// Created by huxf on 2016/7/20.
//

#include "scene_manager.h"

using namespace std;

Camera *SceneManager::CreateCamera(const std::string& name)
{

//    if(cameras_.find(name) != cameras_.end())
//    {
//
//    }

    shared_ptr<Camera> camera = make_shared<Camera>();
    cameras_.insert(CameraMap::value_type(name,camera));

    return camera.get();
}