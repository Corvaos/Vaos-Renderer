#pragma once

#include "vaos/renderer/GLFWContext.h"

#include <fstream>
#include <sstream>
#include <vector>

namespace vaos::renderer {
struct Shader {
  // -------------- STATIC VARS --------------
  static inline std::string prefix; // = ""

  static void setAssetLocationPrefix(const std::string& a);

  // -------------- COMPILE SHADERS --------------
  static void checkShaderCompile(unsigned int vertexShader);

  static std::string readShader(const std::string& filePath);

  static unsigned int compileShader(const std::string& vertexFilePath, const std::string& fragmentFilePath);

  static inline std::vector<unsigned int> shaderPrograms = {};
};

} // namespace vaos::renderer