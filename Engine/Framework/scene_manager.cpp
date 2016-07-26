//
// Created by huxf on 2016/7/20.
//

#include "scene_manager.h"


SceneManager::SceneManager() :
        rootSceneNode_(nullptr),
        sceneNodes_({})
{
}

SceneManager::~SceneManager()
{
}

shared_ptr<SceneNode> SceneManager::GetRootSceneNode()
{
    if( !rootSceneNode_ )
    {
//        rootSceneNode_ =
    }
    return rootSceneNode_;
}

shared_ptr<SceneNode> SceneManager::CreateSceneNode()
{
    return nullptr;
}

shared_ptr<SceneNode> SceneManager::CreateSceneNode(const string &name)
{
    return nullptr;
}

shared_ptr<SceneNode> SceneManager::CreateSceneNodeImpl()
{
    return nullptr;
}

shared_ptr<SceneNode> SceneManager::CreateSceneNodeImpl(const string &name)
{
    return nullptr;
}
