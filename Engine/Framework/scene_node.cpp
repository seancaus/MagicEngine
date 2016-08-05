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

    shared_ptr<SceneNode> SceneNode::CreateChild(const Vector3 &translate) {
        auto cn = CreateChildImpl();
        cn->Translate(translate);
        AddChild(cn);
        return cn;
    }

    shared_ptr<SceneNode> SceneNode::CreateChild(const string &name, const Vector3 &translate) {
        auto cn = CreateChildImpl(name);
        cn->Translate(translate);
        AddChild(cn);
        return cn;
    }

    shared_ptr<SceneNode> SceneNode::CreateChildImpl()
    {
        assert(creator_);
        return creator_->CreateSceneNode();
    }

    shared_ptr<SceneNode> SceneNode::CreateChildImpl(const string &name)
    {
        assert(creator_);
        return creator_->CreateSceneNode(name);
    }

    void SceneNode::FindVisibleObjects(Camera* cam, RenderQueue* queue)
    {

    }

    const string &SceneNode::GetName() const
    {
        return name_;
    }


    void SceneNode::AddChild(shared_ptr<SceneNode> node)
    {
        childrenNodes_[node->GetName()] = node;
    }

    void SceneNode::Translate(const Vector3 &p)
    {

    }
}