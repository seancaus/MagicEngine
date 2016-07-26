//
// Created by huxf on 2016/7/20.
//

#ifndef MAGICCUBE_SCENE_MANAGER_H
#define MAGICCUBE_SCENE_MANAGER_H

#include <memory>
#include "scene_node.h"

using namespace std;

class SceneManager {

public:
    SceneManager() ;
    virtual ~SceneManager() ;

    shared_ptr<SceneNode> GetRootSceneNode();

    virtual shared_ptr<SceneNode> CreateSceneNode();
    virtual shared_ptr<SceneNode> CreateSceneNode(const string& name);

protected:

    virtual shared_ptr<SceneNode> CreateSceneNodeImpl();
    virtual shared_ptr<SceneNode> CreateSceneNodeImpl(const string& name);

    map<string,shared_ptr<SceneNode>> sceneNodes_;
    shared_ptr<SceneNode> rootSceneNode_;
};


#endif //MAGICCUBE_SCENE_MANAGER_H
