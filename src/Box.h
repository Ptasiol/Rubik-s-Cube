#ifndef BOX_H
#define BOX_H

#include "Model.h"

class Box : public Model
{
 public:
    glm::vec3 position;
    glm::vec3* normalF = new glm::vec3 [6];
    Box(float rx = 1.f, float ry = 1.f, float rz = 1.f,
        float r = 0.f, float g = 0.f, float b = 0.f
        );
    ~Box();
};

#endif
