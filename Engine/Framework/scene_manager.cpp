//
// Created by huxf on 2016/7/20.
//

#include <cassert>
#include <iostream>

#include "camera.h"
#include "scene_manager.h"
#include "render_queue.h"
#include "scene_node.h"
#include "entity.h"

using namespace std;

namespace Magic {

    SceneManager::SceneManager() :
            rootSceneNode_(nullptr),
            sceneNodes_({}),
            renderQueue_(nullptr)
    {
    }
    //-----------------------------------------------------------------------
    SceneManager::~SceneManager()
    {
    }
    //-----------------------------------------------------------------------
    shared_ptr<ManualObject> SceneManager::createManualObject(const string &name)
    {
        return std::shared_ptr<ManualObject>();
    }
    //-----------------------------------------------------------------------
    shared_ptr<Entity> SceneManager::createEntity(const string &meshName)
    {
        auto entity = make_shared<Entity>();
        return entity;
    }
    //-----------------------------------------------------------------------
    Camera *SceneManager::createCamera(const std::string &name)
    {
        if(cameras_.find(name) != cameras_.end())
        {
            //throws error
            return nullptr;
        }

        shared_ptr<Camera> camera = make_shared<Camera>(name, this);
        cameras_.insert(CameraMap::value_type(name, camera));

        return camera.get();
    }
    //-----------------------------------------------------------------------
    shared_ptr<SceneNode> SceneManager::createSceneNode()
    {
        //TODO
        auto sn = createSceneNodeImpl();
        assert(sceneNodes_.find(sn->getName()) == sceneNodes_.end());
        sceneNodes_[sn->getName()] = sn;
        return sn;
    }
    //-----------------------------------------------------------------------
    shared_ptr<SceneNode> SceneManager::createSceneNode(const string &name)
    {
        if (sceneNodes_.find(name) != sceneNodes_.end())
        {
            ////TODO exception
        }

        auto sn = createSceneNodeImpl(name);
        sceneNodes_[sn->getName()] = sn;
        return sn;
    }
    //-----------------------------------------------------------------------
    shared_ptr<SceneNode> SceneManager::getRootSceneNode()
    {
        if (!rootSceneNode_)
        {
            rootSceneNode_ = createSceneNode("root");
        }
        return rootSceneNode_;
    }
    //-----------------------------------------------------------------------
    RenderQueue *SceneManager::getRenderQueue()
    {
        if(!renderQueue_)
        {
            initRenderQueue();
        }
        return renderQueue_.get();
    }
    //-----------------------------------------------------------------------
    void SceneManager::initRenderQueue()
    {
        renderQueue_ = make_shared<RenderQueue>();
    }
    //-----------------------------------------------------------------------
    shared_ptr<SceneNode> SceneManager::createSceneNodeImpl()
    {
        return make_shared<SceneNode>(this);
    }
    //-----------------------------------------------------------------------
    shared_ptr<SceneNode> SceneManager::createSceneNodeImpl(const string &name)
    {
        return make_shared<SceneNode>(this, name);
    }
    //-----------------------------------------------------------------------
    void SceneManager::renderScene(Camera *camera, Viewport *vp)
    {
        updateSceneGraph();
        prepareRenderQueue();
        findVisibleObjects(camera);
        renderVisibleObjects();
    }
    //-----------------------------------------------------------------------
    void SceneManager::updateSceneGraph()
    {
        //更新sceneNode的包围盒
    }
    //-----------------------------------------------------------------------
    void SceneManager::prepareRenderQueue()
    {

    }
    //-----------------------------------------------------------------------
    void SceneManager::findVisibleObjects(Camera* camera)
    {
        getRootSceneNode()->findVisibleObjects(camera, getRenderQueue());
    }
    //-----------------------------------------------------------------------
    void SceneManager::renderVisibleObjects()
    {

    }
}