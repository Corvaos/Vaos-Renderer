#pragma once

#include "vaos/renderer/GLFWContext.h"
#include "vaos/renderer/Numerics/Transform.h"
#include "vaos/renderer/Shader.h"

namespace vaos::renderer {

class Material {
  unsigned int shader;
  GLuint transformLocation;

  // UNIMPLEMENTED
  float roughness;

public:
  Material(unsigned int shader) : shader(shader) {
    transformLocation = glGetUniformLocation(shader, "model");
    if (transformLocation == -1) {
      std::cerr << "Model uniform not found\n";
    }
  }

  void useShader(vaos::numerics::Transform transform) {
    vaos::numerics::Matrix4 matrix = transform.matrix();

    glUseProgram(shader);

    glUniformMatrix4fv(transformLocation, 1, GL_FALSE, matrix.data.data());
  }
};

} // namespace vaos::renderer