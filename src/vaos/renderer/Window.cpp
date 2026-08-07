#include "Window.h"
#include "RenderObject.h"
#include <GLFW/glfw3.h>

// ------------------- WINDOW INSTATIATION -------------------
vaos::renderer::Window::Window (std::string name, int windowWidth, int windowHeight) {
	programWindow = glfwCreateWindow(windowWidth, windowHeight, name.c_str(), NULL, NULL);

	if (!programWindow) {
		std::cerr << "Failed to create window" << std::endl;
		return;
	}

	glfwSetFramebufferSizeCallback(programWindow, Window::framebuffer_size_callback);
	glfwSetKeyCallback(programWindow, Window::key_callback);
	// glfwSetScrollCallback(window, scroll_callback);                                              // TODO
	
	
	glfwMakeContextCurrent(programWindow);
	glfwSwapInterval(1);

	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cerr << "Failed to init glad" << std::endl;
		return;
	}

	int width, height;
	glfwGetFramebufferSize(programWindow, &width, &height);

	glViewport(0, 0, width, height);
}

// ------------------- CALLBACKS -------------------
void vaos::renderer::Window::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height); // SETUP VIEWPORT
}


void vaos::renderer::Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {

	if (action == GLFW_PRESS || action == GLFW_REPEAT) {
		switch (key) {
			// Exit
			case GLFW_KEY_ESCAPE:
				glfwSetWindowShouldClose(window, true);
				return;
		}
	}
}

// ------------------- OPERATIONS -------------------
void vaos::renderer::Window::render(const std::vector<RenderObject> objects) {
	active = !glfwWindowShouldClose(programWindow);
	if (!active) {
		return;
	}

	glfwPollEvents();

	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

	for (const vaos::renderer::RenderObject& object : objects) {
		object.draw();
	}

	glfwSwapBuffers(programWindow);
}