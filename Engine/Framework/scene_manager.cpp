//
// Created by huxf on 2016/7/20.
//

#include <cassert>

#include "camera.h"
#include "scene_manager.h"
#include "render_queue.h"
#include "scene_node.h"

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
    Camera *SceneManager::CreateCamera(const std::string &name)
    {
    //    if(cameras_.find(name) != cameras_.end())
    //    {
    //    }

        shared_ptr<Camera> camera = make_shared<Camera>();
        cameras_.insert(CameraMap::value_type(name, camera));

        return camera.get();
    }
    //-----------------------------------------------------------------------
    shared_ptr<SceneNode> SceneManager::CreateSceneNode()
    {
        //TODO
        auto sn = CreateSceneNodeImpl();
        assert(sceneNodes_.find(sn->GetName()) == sceneNodes_.end());
        sceneNodes_[sn->GetName()] = sn;
        return sn;
    }
    //-----------------------------------------------------------------------
    shared_ptr<SceneNode> SceneManager::CreateSceneNode(const string &name)
    {
        if (sceneNodes_.find(name) != sceneNodes_.end())
        {
            ////TODO exception
        }

        auto sn = CreateSceneNodeImpl(name);
        sceneNodes_[sn->GetName()] = sn;
        return sn;
    }
    //-----------------------------------------------------------------------
    shared_ptr<SceneNode> SceneManager::GetRootSceneNode()
    {
        if (!rootSceneNode_)
        {
            rootSceneNode_ = CreateSceneNode("root");
        }
        return rootSceneNode_;
    }
    //-----------------------------------------------------------------------
    RenderQueue *SceneManager::GetRenderQueue()
    {
        if(!renderQueue_)
        {
            InitRenderQueue();
        }
        return renderQueue_.get();
    }
    //-----------------------------------------------------------------------
    void SceneManager::InitRenderQueue()
    {
        renderQueue_ = make_shared<RenderQueue>();
    }
    //-----------------------------------------------------------------------
    shared_ptr<SceneNode> SceneManager::CreateSceneNodeImpl()
    {
        auto sn = make_shared<SceneNode>(this);
        return sn;
    }
    //-----------------------------------------------------------------------
    shared_ptr<SceneNode> SceneManager::CreateSceneNodeImpl(const string &name)
    {
        return make_shared<SceneNode>(this, name);
    }
    //-----------------------------------------------------------------------
    void SceneManager::RenderScene(Camera *camera, Viewport *vp, bool includeOverlays)
    {
        UpdateSceneGraph();
        PrepareRenderQueue();
        FindVisibleObjects();
        RenderVisibleObjects();
    }
    //-----------------------------------------------------------------------
    void SceneManager::UpdateSceneGraph()
    {

    }
    //-----------------------------------------------------------------------
    void SceneManager::PrepareRenderQueue()
    {

    }
    //-----------------------------------------------------------------------
    void SceneManager::FindVisibleObjects()
    {
        GetRootSceneNode()->FindVisibleObjects(nullptr,GetRenderQueue());
    }
    //-----------------------------------------------------------------------
    void SceneManager::RenderVisibleObjects()
    {

    }
}