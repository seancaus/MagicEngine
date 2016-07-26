//
// Created by Ziv on 16/7/16.
//

#ifndef MAGICCUBE_SCENE_NODE_H
#define MAGICCUBE_SCENE_NODE_H

#include <map>
#include <memory>

#include "object.h"
#include "movable_object.h"
#include "vector3.h"

using namespace std;

class SceneManager;

class SceneNode :public Object{

public:

    SceneNode(SceneManager* creator);
    SceneNode(SceneManager* creator,const string& name);
    virtual ~SceneNode();

    virtual shared_ptr<SceneNode>createChild(const Vector3& translate);
    virtual shared_ptr<SceneNode>createChild(const string& name, const Vector3& translate);

    void addChild(shared_ptr<SceneNode> node);

    const string& getName() const;

    void translate(const Vector3& p);

protected:

    virtual shared_ptr<SceneNode>createChildImpl();
    virtual shared_ptr<SceneNode>createChildImpl(const string& name);


    string name_;
    SceneManager* creator_;

    map<string,shared_ptr<MovableObject>> attachObjects_;
    map<string,shared_ptr<SceneNode>> childrenNodes_;

};


#endif //MAGICCUBE_SCENE_NODE_H
