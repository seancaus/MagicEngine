//
// Created by Ziv on 16/7/16.
//

#ifndef MAGICCUBE_SCENE_H
#define MAGICCUBE_SCENE_H

#include <map>
#include <memory>

#include "object.h"
#include "movable_object.h"
#include "vector3.h"
#include "scene_manager.h"

using namespace std;

class SceneNode :public Object{

public:

    SceneNode(SceneManager* creator);
    virtual ~SceneNode();

    virtual shared_ptr<SceneNode>createChild(const Vector3& translate);
    virtual shared_ptr<SceneNode>createChild(const string& name, const Vector3& translate);

protected:

    virtual shared_ptr<SceneNode>createChildImpl();
    virtual shared_ptr<SceneNode>createChildImpl(const string& name);


    string name_;
    SceneManager* creator_;

    map<string,shared_ptr<MovableObject>> attachObjects_;
    map<string,shared_ptr<SceneNode>> childrenNodes_;

};


#endif //MAGICCUBE_SCENE_H
