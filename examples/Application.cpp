#include "Mesh/MeshFactory.h"
#include "RenderObject.h"
#include "Window.h"

    // Ease of access
using namespace vaos::renderer;
using Vector3 = vaos::numerics::Vector3;

void runApplication() {
      // Prepare OpenGL
  GLFWContext::init();

      // Create User Window
  Window window = Window("Window 1", 1920, 1080);

      // Generate and cache square
  MeshFactory::generateSquare();

      // Create asset location
  Shader::setAssetLocationPrefix("../../../assets/");
  Shader::compileShader("vertex.glsl", "fragment.glsl");
  Material material = Material(Shader::shaderPrograms[0]);

      // Make object list
  std::vector<RenderObject> objects = {};
  objects.push_back(RenderObject(MeshFactory::meshes.at("square"), material));
      // Add posititional offset, scaling, and rotation
  objects[0].transform = vaos::numerics::Transform(
      Vector3(-0.25, -0.25, 0), Vector3(0, 0, 3.14 / 3), Vector3(0.5, 0.5, 1));

      // Rendering loop
  while (window.active) {
    window.render(objects);
  }

      // Clean up
  glfwTerminate();
}

    // Run
int main() {
  runApplication();

  return 0;
}