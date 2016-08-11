//
// Created by Ziv on 16/7/16.
//

#include <cassert>
#include "scene_node.h"
#include "scene_manager.h"
#include "render_queue.h"

namespace Magic {

    SceneNode::SceneNode(SceneManager *creator) :
            creator_(creator)
    {
    }
    //-----------------------------------------------------------------------
    SceneNode::SceneNode(SceneManager *creator, const string &name) :
            creator_(creator),
            name_(name)
    {

    }
    //-----------------------------------------------------------------------
    SceneNode::~SceneNode()
    {
    }
    //-----------------------------------------------------------------------
    shared_ptr<SceneNode> SceneNode::createChild(const Vector3 &translate) {
        auto cn = createChildImpl();
        cn->translate(translate);
        addChild(cn);
        return cn;
    }
    //-----------------------------------------------------------------------
    shared_ptr<SceneNode> SceneNode::createChild(const string &name, const Vector3 &translate) {
        auto cn = createChildImpl(name);
        cn->translate(translate);
        addChild(cn);
        return cn;
    }
    //-----------------------------------------------------------------------
    shared_ptr<SceneNode> SceneNode::createChildImpl()
    {
        assert(creator_);
        return creator_->createSceneNode();
    }
    //-----------------------------------------------------------------------
    shared_ptr<SceneNode> SceneNode::createChildImpl(const string &name)
    {
        assert(creator_);
        return creator_->createSceneNode(name);
    }
    //-----------------------------------------------------------------------
    void SceneNode::attachObject(shared_ptr<MovableObject> object)
    {
        attachObjects_[object->getName()] = object;
    }
    //-----------------------------------------------------------------------
    void SceneNode::findVisibleObjects(Camera* cam, RenderQueue* queue)
    {
        for(auto it : attachObjects_)
        {
            auto mo = it.second;
            queue->processVisibleObject(mo.get(),cam);
        }

        for (auto it : children_)
        {
            auto childNode = static_cast<SceneNode*>(it.second.get());
            childNode->findVisibleObjects(cam,queue);
        }
    }
    //-----------------------------------------------------------------------
    const string &SceneNode::getName() const
    {
        return name_;
    }
    //-----------------------------------------------------------------------
    void SceneNode::addChild(shared_ptr<SceneNode> node)
    {
        children_[node->getName()] = node;
    }
    //-----------------------------------------------------------------------
    void SceneNode::translate(const Vector3 &p)
    {

    }
    //-----------------------------------------------------------------------
}