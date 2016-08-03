//
// Created by huxf on 2016/7/20.
//

#include <cassert>
#include "scene_manager.h"

using namespace std;

namespace Magic {
    Camera *SceneManager::CreateCamera(const std::string &name) {

//    if(cameras_.find(name) != cameras_.end())
//    {
//
//    }

        shared_ptr<Camera> camera = make_shared<Camera>();
        cameras_.insert(CameraMap::value_type(name, camera));

        return camera.get();
    }

    SceneManager::SceneManager() :
            rootSceneNode_(nullptr),
            sceneNodes_({}) {
    }

    SceneManager::~SceneManager() {
    }

    shared_ptr<SceneNode> SceneManager::GetRootSceneNode() {
        if (!rootSceneNode_) {
            rootSceneNode_ = CreateSceneNode("root");
        }
        return rootSceneNode_;
    }

    shared_ptr<SceneNode> SceneManager::CreateSceneNode() {
        //TODO
        auto sn = CreateSceneNodeImpl();
        assert(sceneNodes_.find(sn->getName()) == sceneNodes_.end());
        sceneNodes_[sn->getName()] = sn;
        return sn;
    }

    shared_ptr<SceneNode> SceneManager::CreateSceneNode(const string &name) {
        if (sceneNodes_.find(name) != sceneNodes_.end()) {
            ////TODO exception
        }

        auto sn = CreateSceneNodeImpl(name);
        sceneNodes_[sn->getName()] = sn;
        return sn;
    }

    shared_ptr<SceneNode> SceneManager::CreateSceneNodeImpl() {
        auto sn = make_shared<SceneNode>(this);
        return sn;
    }

    shared_ptr<SceneNode> SceneManager::CreateSceneNodeImpl(const string &name) {
        return make_shared<SceneNode>(this, name);
    }


    void SceneManager::RenderScene(Camera *camera, Viewport *vp, bool includeOverlays)
    {

    }

}