//
// Created by Ziv on 16/7/16.
//

#ifndef MAGICCUBE_SCENE_NODE_H
#define MAGICCUBE_SCENE_NODE_H

#include <map>
#include <memory>
#include <string>

#include "node.h"
#include "movable_object.h"
#include "vector3.h"

using namespace std;

namespace Magic {

    class SceneManager;
    class Camera;
    class RenderQueue;

    class SceneNode : public Node {

    public:

        SceneNode(SceneManager *creator);
        SceneNode(SceneManager *creator, const string &name);
        virtual ~SceneNode();

        virtual shared_ptr<SceneNode> CreateChild(const Vector3 &translate);
        virtual shared_ptr<SceneNode> CreateChild(const string &name, const Vector3 &translate);
        void AddChild(shared_ptr<SceneNode> node);
        void AttachObject(shared_ptr<MovableObject> object);

        void FindVisibleObjects(Camera* cam, RenderQueue* queue /**,VisibleObjectsBoundsInfo* visibleBounds*/);

        const string &GetName() const;

        void Translate(const Vector3 &p);

    protected:

        virtual shared_ptr<SceneNode> CreateChildImpl();
        virtual shared_ptr<SceneNode> CreateChildImpl(const string &name);

        string name_;
        SceneManager* creator_;

        map<string, shared_ptr<MovableObject>> attachObjects_;
        map<string, shared_ptr<SceneNode>> childrenNodes_;
    };
}

#endif //MAGICCUBE_SCENE_NODE_H
