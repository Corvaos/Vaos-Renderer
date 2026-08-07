#pragma once

#include "GLFWContext.h"

#include <fstream>
#include <sstream>
#include <vector>

namespace vaos::renderer {
struct Shader {
  // -------------- STATIC VARS --------------
  static inline std::string prefix = "";

  static void setAssetLocationPrefix(std::string a);

  // -------------- COMPILE SHADERS --------------
  static void checkShaderCompile(unsigned int vertexShader);

  static std::string readShader(std::string filePath);

  static unsigned int compileShader(std::string vertexFilePath, std::string fragmentFilePath);

  static inline std::vector<unsigned int> shaderPrograms = {};
};

} // namespace vaos::renderer