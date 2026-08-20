#pragma once

#include "vaos/renderer/GLFWContext.h"
#include "vaos/renderer/Numerics/Transform.h"
#include "vaos/renderer/Shader.h"

#include <memory>

namespace vaos::renderer
{
  class Material
  {
    const unsigned int shader;
    GLint transformLocation;
    GLint projectionLocation;

    // UNIMPLEMENTED
    const float roughness{-1};

  public:
    explicit Material(unsigned int shader);
    Material(const std::string& vertex, const std::string& fragment);

    void useShader(const vaos::numerics::Transform& transform, float aspect) const;

    inline static std::vector<std::unique_ptr<Material>> materials = {};
  };
} // namespace vaos::renderer
