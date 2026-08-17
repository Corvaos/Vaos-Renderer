#pragma once

// STD
#include <iostream>
#include <string>
#include <vector>

// OpenGL
#include "vaos/renderer/GLFWContext.h"
#include "vaos/renderer/RenderObject.h"

namespace vaos::renderer
{
	class Window
	{
	private:
		int width = 1920;
		int height = 1080;

		GLFWwindow* programWindow;

	public:
		Window(const std::string& name, const int& width, const int& height);

		bool active = true;
		numerics::Vector3 backgroundColor = numerics::Vector3(0, 0, 0);

		std::vector<RenderObject> objects;

		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

		void render();
	};
} // namespace vaos::renderer
