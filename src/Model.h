#ifndef MODEL_H
#define MODEL_H

#include "Mesh.h"
#include "Shader.h"

class Model
{
public:
  int nMeshes;
  Mesh **meshes;
  glm::mat4 localTransform;

public:
  Model();
  void Draw(Shader* shader_);
  void SetLocalTransform(glm::mat4& localTransform_);
  const glm::mat4& GetLocalTransform() const;
};

#endif
