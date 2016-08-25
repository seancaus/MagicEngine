//
// Created by huxf on 2016/7/20.
//

#ifndef MAGICCUBE_SCENE_MANAGER_H
#define MAGICCUBE_SCENE_MANAGER_H

#include <string>
#include <map>
#include <memory>

using namespace std;

namespace magic {

    class Camera;
    class SceneNode;
    class RenderQueue;
    class Viewport;
    class Entity;
    class ManualObject;

    typedef map<string, shared_ptr<Camera>> CameraMap;

    class SceneManager {

    public:
        SceneManager();
        virtual ~SceneManager();

        virtual shared_ptr<ManualObject> createManualObject(const string& name);
        virtual shared_ptr<Entity>createEntity(const string& meshName);
        virtual shared_ptr<SceneNode> createSceneNode();
        virtual shared_ptr<SceneNode> createSceneNode(const string &name);
        virtual Camera *createCamera(const std::string &name);

        RenderQueue* getRenderQueue();
        shared_ptr<SceneNode> getRootSceneNode();

        virtual void renderScene(Camera* camera, Viewport* vp);
        virtual void updateSceneGraph();
        virtual void prepareRenderQueue();
        virtual void findVisibleObjects(Camera* camera);
        virtual void renderVisibleObjects();

    protected:

        void initRenderQueue();
        virtual shared_ptr<SceneNode> createSceneNodeImpl();
        virtual shared_ptr<SceneNode> createSceneNodeImpl(const string &name);

        CameraMap                           cameras_;
        map<string, shared_ptr<SceneNode>>  sceneNodes_;
        shared_ptr<SceneNode>               rootSceneNode_;
        shared_ptr<RenderQueue>             renderQueue_;
    };
}

#endif //MAGICCUBE_SCENE_MANAGER_H
