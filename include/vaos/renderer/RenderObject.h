#pragma once

#include "vaos/renderer/GLFWContext.h"
#include "vaos/renderer/Material.h"
#include "vaos/renderer/Mesh/Mesh.h"
#include "vaos/renderer/Numerics/Transform.h"

namespace vaos::renderer {
class RenderObject {
public:
  Mesh &mesh;
  vaos::numerics::Transform transform;
  Material &shader;

  RenderObject(Mesh &mesh, Material &shader)
      : mesh(mesh), transform(vaos::numerics::Transform()), shader(shader) {}

  void draw() const {
    glBindVertexArray(mesh.vao);
    shader.useShader(transform);
    glDrawElements(GL_TRIANGLES, mesh.indexCount, GL_UNSIGNED_INT, nullptr);
  }
};
} // namespace vaos::renderer