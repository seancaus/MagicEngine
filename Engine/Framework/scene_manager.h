//
// Created by huxf on 2016/7/20.
//

#ifndef MAGICCUBE_SCENE_MANAGER_H
#define MAGICCUBE_SCENE_MANAGER_H

#include <string>
#include <map>
#include <memory>
#include "camera.h"

using namespace std;

class SceneManager {

public:

    virtual Camera* CreateCamera(const std::string& name);


protected:

    typedef map<string, shared_ptr<Camera>> CameraMap;
    CameraMap cameras_;

};


#endif //MAGICCUBE_SCENE_MANAGER_H
