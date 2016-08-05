//
// Created by huxf on 2016/7/20.
//

#ifndef MAGICCUBE_SCENE_MANAGER_H
#define MAGICCUBE_SCENE_MANAGER_H

#include <string>
#include <map>
#include <memory>

using namespace std;

namespace Magic {

    class Camera;
    class SceneNode;
    class RenderQueue;
    class Viewport;

    typedef map<string, shared_ptr<Camera>> CameraMap;

    class SceneManager {

    public:

        SceneManager();
        virtual ~SceneManager();

        virtual shared_ptr<SceneNode> CreateSceneNode();
        virtual shared_ptr<SceneNode> CreateSceneNode(const string &name);
        virtual Camera *CreateCamera(const std::string &name);

        RenderQueue* GetRenderQueue();
        shared_ptr<SceneNode> GetRootSceneNode();

        virtual void RenderScene(Camera* camera, Viewport* vp, bool includeOverlays);
        virtual void UpdateSceneGraph();
        virtual void PrepareRenderQueue();
        virtual void FindVisibleObjects();
        virtual void RenderVisibleObjects();

    protected:

        void InitRenderQueue();
        virtual shared_ptr<SceneNode> CreateSceneNodeImpl();
        virtual shared_ptr<SceneNode> CreateSceneNodeImpl(const string &name);

        map<string, shared_ptr<SceneNode>>  sceneNodes_;
        shared_ptr<SceneNode>               rootSceneNode_;
        CameraMap                           cameras_;
        shared_ptr<RenderQueue>             renderQueue_;
    };
}

#endif //MAGICCUBE_SCENE_MANAGER_H
