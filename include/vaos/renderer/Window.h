#pragma once

// STD
#include <iostream>
#include <string>
#include <vector>

// OpenGL
#include "GLFWContext.h"

#include "RenderObject.h"

namespace vaos::renderer {

class Window {
private:
  int width;
  int height;

  GLFWwindow *programWindow;

public:
  Window (std::string name, int width, int height);

  bool active = true;

  static void error_callback(int error, const char *description);
  static void framebuffer_size_callback(GLFWwindow *window, int width,
                                        int height);
  static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

  void render(std::vector<RenderObject> objects);
};

} // namespace vaos::renderer