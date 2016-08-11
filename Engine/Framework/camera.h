//
// Created by huxf on 2016/7/19.
//

#ifndef MAGICCUBE_CAMERA_H
#define MAGICCUBE_CAMERA_H

#include <string>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "object.h"
#include "Viewport.h"
#include "vector3.h"

using namespace std;

namespace Magic {

    class SceneManager;

    class Camera : public Object {
    public:

        Camera(const string& name, SceneManager* sm);
        virtual ~Camera();

        virtual void lookAt(float x, float y, float z);
        virtual void lookAt(const Vector3& targetPoint);

        virtual glm::mat4 getViewMatrix();

        virtual void renderScene(Viewport *vp);

    protected:

        SceneManager*   sceneMgr_;
        string          name_;

        glm::mat4       viewMatrix_;

    };
}

#endif //MAGICCUBE_CAMERA_H
