#include "Model.h"

Model::Model()
{
  nMeshes = 0;
  meshes = NULL;
  localTransform = glm::mat4(1.f);
}

void Model::Draw(Shader* shader_)
{
  for( int i = 0; i < nMeshes; i++ ){
    glm::mat4 model = localTransform * meshes[i]->localTransform;
    shader_->SetMat4("model", model);

    glm::mat3 normal = glm::mat3(glm::inverse(glm::transpose(model)));
    shader_->SetMat4("normal", normal);

    glBindVertexArray(meshes[i]->VAO);
    glDrawElements(GL_TRIANGLES, meshes[i]->indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
  }
}

void Model::SetLocalTransform(glm::mat4& localTransform_)
{
  localTransform = localTransform_;
}

const glm::mat4& Model::GetLocalTransform() const
{
  return localTransform;
}
