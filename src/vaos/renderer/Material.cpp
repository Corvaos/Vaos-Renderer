//
// Created by corvaos on 8/18/26.
//

#include "vaos/renderer/Material.h"

vaos::renderer::Material::Material(const unsigned int shader) : shader(shader)
{
  transformLocation = glGetUniformLocation(shader, "model");
  if (transformLocation == -1)
  {
    std::cerr << "Model uniform not found\n";
  }

  projectionLocation = glGetUniformLocation(shader, "projection");
  if (projectionLocation == -1)
  {
    std::cerr << "Projection uniform not found\n";
  }

  materials.emplace_back(std::make_unique<Material>(*this));
}

vaos::renderer::Material::Material(const std::string& vertex, const std::string& fragment) : shader(
  Shader::compileShader(vertex, fragment))
{
  transformLocation = glGetUniformLocation(shader, "model");
  if (transformLocation == -1)
  {
    std::cerr << "Model uniform not found\n";
  }

  projectionLocation = glGetUniformLocation(shader, "projection");
  if (projectionLocation == -1)
  {
    std::cerr << "Projection uniform not found\n";
  }

  materials.emplace_back(std::make_unique<Material>(*this));
}

void vaos::renderer::Material::useShader(const vaos::numerics::Transform& transform, const float aspect) const
{
  glUseProgram(shader);

  glUniformMatrix4fv(transformLocation, 1, GL_FALSE, transform.matrix().data.data());
  glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, numerics::Matrix<float, 4, 4>::projection(aspect).data.data());
}
