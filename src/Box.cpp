#include "Box.h"

Box::Box(
    float rx, float ry, float rz,
    float r, float g, float b
)
{
    nMeshes = 6;
    meshes = new Mesh* [6];

    int nVertices = 4;
    int nIndices = 6;

    //Vertex *vertices = new Vertex [nVertices];
    //unsigned int *indices = new unsigned int [nIndices];
    std::vector <Vertex> vertices(nVertices);
    std::vector <unsigned int> indices(nIndices);

    vertices[0].position = glm::vec3(-rx, -ry, rz);
    vertices[0].color = glm::vec3(r, 1.f, b);
    vertices[0].normal = glm::vec3(0.f, 0.f, 1.f);
    vertices[1].position = glm::vec3( rx, -ry, rz);
    vertices[1].color = glm::vec3(r, 1.f, b);
    vertices[1].normal = glm::vec3(0.f, 0.f, 1.f);
    vertices[2].position = glm::vec3(-rx,  ry, rz);
    vertices[2].color = glm::vec3(r, 1.f, b);
    vertices[2].normal = glm::vec3(0.f, 0.f, 1.f);
    vertices[3].position = glm::vec3( rx,  ry, rz);
    vertices[3].color = glm::vec3(r, 1.f, b);
    vertices[3].normal = glm::vec3(0.f, 0.f, 1.f);

    indices[0] = 0;
    indices[1] = 1;
    indices[2] = 2;
    indices[3] = 1;
    indices[4] = 3;
    indices[5] = 2;

    meshes[0] = new Mesh(vertices, indices);

    vertices[0].position = glm::vec3(rx, -ry, rz);
    vertices[0].color = glm::vec3(1.f, g, b);
    vertices[0].normal = glm::vec3(1.f, 0.f, 0.f);
    vertices[1].position = glm::vec3(rx, -ry, -rz);
    vertices[1].color = glm::vec3(1.f, g, b);
    vertices[1].normal = glm::vec3(1.f, 0.f, 0.f);
    vertices[2].position = glm::vec3(rx,  ry, rz);
    vertices[2].color = glm::vec3(1.f, g, b);
    vertices[2].normal = glm::vec3(1.f, 0.f, 0.f);
    vertices[3].position = glm::vec3(rx,  ry, -rz);
    vertices[3].color = glm::vec3(1.f, g, b);
    vertices[3].normal = glm::vec3(1.f, 0.f, 0.f);

    meshes[1] = new Mesh(vertices, indices);

    vertices[0].position = glm::vec3(rx, -ry, -rz);
    vertices[0].color = glm::vec3(r, g, 1.f);
    vertices[0].normal = glm::vec3(0.f, 0.f, -1.f);
    vertices[1].position = glm::vec3(-rx, -ry, -rz);
    vertices[1].color = glm::vec3(r, g, 1.f);
    vertices[1].normal = glm::vec3(0.f, 0.f, -1.f);
    vertices[2].position = glm::vec3(rx,  ry, -rz);
    vertices[2].color = glm::vec3(r, g, 1.f);
    vertices[2].normal = glm::vec3(0.f, 0.f, -1.f);
    vertices[3].position = glm::vec3(-rx,  ry, -rz);
    vertices[3].color = glm::vec3(r, g, 1.f);
    vertices[3].normal = glm::vec3(0.f, 0.f, -1.f);

    meshes[2] = new Mesh(vertices, indices);

    vertices[0].position = glm::vec3(-rx, -ry, -rz);
    vertices[0].color = glm::vec3(1.f, 0.5f, b);
    vertices[0].normal = glm::vec3(-1.f, 0.f, 0.f);
    vertices[1].position = glm::vec3(-rx, -ry, rz);
    vertices[1].color = glm::vec3(1.f, 0.5f, b);
    vertices[1].normal = glm::vec3(-1.f, 0.f, 0.f);
    vertices[2].position = glm::vec3(-rx, ry, -rz);
    vertices[2].color = glm::vec3(1.f, 0.5f, b);
    vertices[2].normal = glm::vec3(-1.f, 0.f, 0.f);
    vertices[3].position = glm::vec3(-rx, ry, rz);
    vertices[3].color = glm::vec3(1.f, 0.5f, b);
    vertices[3].normal = glm::vec3(-1.f, 0.f, 0.f);

    meshes[3] = new Mesh(vertices, indices);

    vertices[0].position = glm::vec3(-rx, ry, rz);
    vertices[0].color = glm::vec3(1.f, 1.f, 1.f);
    vertices[0].normal = glm::vec3(0.f, 1.f, 0.f);
    vertices[1].position = glm::vec3(rx, ry, rz);
    vertices[1].color = glm::vec3(1.f, 1.f, 1.f);
    vertices[1].normal = glm::vec3(0.f, 1.f, 0.f);
    vertices[2].position = glm::vec3(-rx, ry, -rz);
    vertices[2].color = glm::vec3(1.f, 1.f, 1.f);
    vertices[2].normal = glm::vec3(0.f, 1.f, 0.f);
    vertices[3].position = glm::vec3(rx, ry, -rz);
    vertices[3].color = glm::vec3(1.f, 1.f, 1.f);
    vertices[3].normal = glm::vec3(0.f, 1.f, 0.f);

    meshes[4] = new Mesh(vertices, indices);

    vertices[0].position = glm::vec3(-rx, -ry, -rz);
    vertices[0].color = glm::vec3(1.f, 1.f, 0.f);
    vertices[0].normal = glm::vec3(0.f, -1.f, 0.f);
    vertices[1].position = glm::vec3(rx, -ry, -rz);
    vertices[1].color = glm::vec3(1.f, 1.f, 0.f);
    vertices[1].normal = glm::vec3(0.f, -1.f, 0.f);
    vertices[2].position = glm::vec3(-rx, -ry, rz);
    vertices[2].color = glm::vec3(1.f, 1.f, 0.f);
    vertices[2].normal = glm::vec3(0.f, -1.f, 0.f);
    vertices[3].position = glm::vec3(rx, -ry, rz);
    vertices[3].color = glm::vec3(1.f, 1.f, 0.f);
    vertices[3].normal = glm::vec3(0.f, -1.f, 0.f);

    meshes[5] = new Mesh(vertices, indices);

}

Box::~Box()
{
    delete meshes[0];
    delete meshes[1];
    delete meshes[2];
    delete meshes[3];
    delete meshes[4];
    delete meshes[5];
    delete [] meshes;
}
