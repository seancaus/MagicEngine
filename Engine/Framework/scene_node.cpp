//
// Created by Ziv on 16/7/16.
//

#include <cassert>
#include "scene_node.h"

SceneNode::SceneNode(SceneManager* creator):
creator_(creator)
{
}

SceneNode::~SceneNode() {

}

shared_ptr<SceneNode> SceneNode::createChild(const Vector3& translate)
{
    return std::shared_ptr<SceneNode>();
}

shared_ptr<SceneNode> SceneNode::createChild(const string &name,const Vector3& translate)
{
    return std::shared_ptr<SceneNode>();
}

shared_ptr<SceneNode> SceneNode::createChildImpl()
{
    assert(creator_);
    return creator_->CreateSceneNode();
}

shared_ptr<SceneNode> SceneNode::createChildImpl(const string &name)
{
    assert(creator_);
    return creator_->CreateSceneNode(name);
}

