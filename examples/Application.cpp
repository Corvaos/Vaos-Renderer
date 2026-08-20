#include "vaos/renderer/Mesh/MeshFactory.h"
#include "vaos/renderer/RenderObject.h"
#include "vaos/renderer/Window.h"

// Ease of access
using namespace vaos::renderer;
using Vector3 = vaos::numerics::Vector3;

void runApplication()
{
	// Prepare OpenGL
	GLFWContext::init();

	// Create User Window
	Window window = Window("Vaos Renderer", 1920, 1080);

	// Generate and cache square
	MeshFactory::generateSquare();

	// Create asset location
	Shader::setAssetLocationPrefix("../assets/");
	Shader::compileShader("vertex.glsl", "fragment.glsl");
	Material material = Material(Shader::shaderPrograms[0]);

	window.objects.emplace_back(MeshFactory::meshes.at("square"), material);
	// Add positional offset, scaling, and rotation
	window.objects[0].transform = vaos::numerics::Transform(
		Vector3(-0.25, -0.25, 0),
		Vector3(0, 0, 3.14 / 3),
		Vector3(0.5, 0.5, 1));

	// Rendering loop
	while (window.active)
	{
		window.render();
	}

	// Clean up
	GLFWContext::terminate();
}

// Run
int main()
{
	runApplication();

	return 0;
}
