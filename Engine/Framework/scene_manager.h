//
// Created by huxf on 2016/7/20.
//

#ifndef MAGICCUBE_SCENE_MANAGER_H
#define MAGICCUBE_SCENE_MANAGER_H

#include <string>
#include <map>
#include <memory>
#include "camera.h"
#include "scene_node.h"

using namespace std;

namespace Magic {
    class SceneManager {

    public:

        SceneManager();

        virtual ~SceneManager();

        shared_ptr<SceneNode> GetRootSceneNode();

        virtual shared_ptr<SceneNode> CreateSceneNode();

        virtual shared_ptr<SceneNode> CreateSceneNode(const string &name);

        virtual Camera *CreateCamera(const std::string &name);
        virtual void RenderScene(Camera* camera, Viewport* vp, bool includeOverlays);

    protected:

        virtual shared_ptr<SceneNode> CreateSceneNodeImpl();

        virtual shared_ptr<SceneNode> CreateSceneNodeImpl(const string &name);

        map<string, shared_ptr<SceneNode>> sceneNodes_;
        shared_ptr<SceneNode> rootSceneNode_;

        typedef map<string, shared_ptr<Camera>> CameraMap;
        CameraMap cameras_;
    };
}

#endif //MAGICCUBE_SCENE_MANAGER_H
