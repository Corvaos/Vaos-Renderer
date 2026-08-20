#pragma once

#include "vaos/renderer/GLFWContext.h"
#include "vaos/renderer/Material.h"
#include "vaos/renderer/Mesh/Mesh.h"
#include "vaos/renderer/Numerics/Transform.h"

namespace vaos::renderer
{
  class RenderObject
  {
    const Mesh& mesh;
    const Material& shader;

  public:
    vaos::numerics::Transform transform;

    RenderObject(Mesh& mesh, Material& shader)
      : mesh(mesh), shader(shader), transform(vaos::numerics::Transform())
    {
    }

    void draw(const float aspect) const
    {
      glBindVertexArray(mesh.vao);
      shader.useShader(transform, aspect);
      glDrawElements(GL_TRIANGLES, mesh.indexCount, GL_UNSIGNED_INT, nullptr);
    }
  };
} // namespace vaos::renderer
