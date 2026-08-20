#include "vaos/renderer/Window.h"
#include "vaos/renderer/RenderObject.h"
#include <GLFW/glfw3.h>

// ------------------- WINDOW INSTATIATION -------------------
vaos::renderer::Window::Window(const std::string& name, int width, int height)
{
  programWindow = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);

  if (!programWindow)
  {
    std::cerr << "Failed to create window" << std::endl;
    return;
  }

  glfwSetFramebufferSizeCallback(programWindow, Window::framebuffer_size_callback);
  glfwSetKeyCallback(programWindow, Window::key_callback);
  // glfwSetScrollCallback(window, scroll_callback; // TODO


  glfwMakeContextCurrent(programWindow);
  glfwSwapInterval(1);


  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cerr << "Failed to init glad" << std::endl;
    return;
  }

  glfwGetFramebufferSize(programWindow, &width, &height);

  glViewport(0, 0, width, height);
}

// ------------------- CALLBACKS -------------------
void vaos::renderer::Window::framebuffer_size_callback(GLFWwindow* window, const int width, const int height)
{
  glViewport(0, 0, width, height); // SETUP VIEWPORT
}

void vaos::renderer::Window::key_callback(GLFWwindow* window, const int key, const int scancode, const int action, const int mods)
{
  if (action == GLFW_PRESS || action == GLFW_REPEAT)
  {
    switch (key)
    {
    // Exit
    case GLFW_KEY_ESCAPE:
      glfwSetWindowShouldClose(window, true);
      return;
    }
  }
}

// ------------------- OPERATIONS -------------------
void vaos::renderer::Window::render()
{
  active = !glfwWindowShouldClose(programWindow);
  if (!active)
  {
    return;
  }

  glfwPollEvents();

  glfwGetFramebufferSize(programWindow, &width, &height);

  glClearColor(backgroundColor.x, backgroundColor.y, backgroundColor.z, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  for (vaos::renderer::RenderObject& object : objects)
  {
    object.draw(static_cast<float>(width)/static_cast<float>(height));
  }

  glfwSwapBuffers(programWindow);
}
