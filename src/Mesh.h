#ifndef MESH_H
#define MESH_H

#include <iostream>
#include <vector>

#include "Vertex.h"

class Mesh
{
public:
    std::vector <Vertex> vertices;
    std::vector <unsigned int> indices;
    unsigned int VAO, VBO, EBO;
    glm::mat4 localTransform = glm::mat4(1.f);

    Mesh(std::vector <Vertex> vertices_, std::vector <unsigned int> indices_);
    ~Mesh();
    void Draw();
    void SetLocalTransform(glm::mat4& localTransform_);
    const glm::mat4& GetLocalTransform() const;


};

#endif
