//
// Created by Ziv on 16/7/16.
//

#include <cassert>
#include "scene_node.h"
#include "scene_manager.h"

namespace Magic {

    SceneNode::SceneNode(SceneManager *creator) :
            creator_(creator) {
    }

    SceneNode::SceneNode(SceneManager *creator, const string &name) :
            creator_(creator),
            name_(name) {

    }

    SceneNode::~SceneNode() {
    }

    shared_ptr<SceneNode> SceneNode::createChild(const Vector3 &translate) {
        auto cn = createChildImpl();
        cn->translate(translate);
        addChild(cn);
        return cn;
    }

    shared_ptr<SceneNode> SceneNode::createChild(const string &name, const Vector3 &translate) {
        auto cn = createChildImpl(name);
        cn->translate(translate);
        addChild(cn);
        return cn;
    }

    shared_ptr<SceneNode> SceneNode::createChildImpl() {
        assert(creator_);
        return creator_->CreateSceneNode();
    }

    shared_ptr<SceneNode> SceneNode::createChildImpl(const string &name) {
        assert(creator_);
        return creator_->CreateSceneNode(name);
    }


    const string &SceneNode::getName() const {
        return name_;
    }


    void SceneNode::addChild(shared_ptr<SceneNode> node) {
        childrenNodes_[node->getName()] = node;
    }

    void SceneNode::translate(const Vector3 &p) {

    }
}