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

    typedef map<string, shared_ptr<MovableObject>> AttachObjectMap;


    class SceneNode : public Node {

    public:

        SceneNode(SceneManager *creator);
        SceneNode(SceneManager *creator, const string &name);
        virtual ~SceneNode();

        virtual shared_ptr<SceneNode> createChild(const Vector3 &translate);
        virtual shared_ptr<SceneNode> createChild(const string &name, const Vector3 &translate);
        void addChild(shared_ptr<SceneNode> node);
        void attachObject(shared_ptr<MovableObject> object);

        void findVisibleObjects(Camera* cam, RenderQueue* queue /**,VisibleObjectsBoundsInfo* visibleBounds*/);

        const string &getName() const;

        void translate(const Vector3 &p);

    protected:

        virtual shared_ptr<SceneNode> createChildImpl();
        virtual shared_ptr<SceneNode> createChildImpl(const string &name);

        string name_;
        SceneManager* creator_;

        AttachObjectMap attachObjects_;

    };
}

#endif //MAGICCUBE_SCENE_NODE_H
