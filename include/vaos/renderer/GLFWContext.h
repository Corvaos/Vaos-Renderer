#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace vaos::renderer {

struct GLFWContext {

  static void init() {
    glfwSetErrorCallback(error_callback);

    if (!glfwInit()) {
      std::cerr << "Failed to init" << std::endl;
      return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  }

  static void error_callback(int error, const char *description) {
    std::cerr << "Error: \n" << description << std::endl;
  }
};

} // namespace vaos::renderer