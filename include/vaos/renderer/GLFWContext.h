#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace vaos::renderer
{
  class GLFWContext
  {
  private:
    static void error_callback(const int error, const char* description)
    {
      std::cerr << "Error: " << error << std::endl << description << std::endl;
    }

  public:
    static void init()
    {
      glfwSetErrorCallback(error_callback);

      if (!glfwInit())
      {
        std::cerr << "Failed to init" << std::endl;
        return;
      }

      glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
      glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
      glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }

    static void terminate()
    {
      glfwTerminate();
    }
  };
} // namespace vaos::renderer
