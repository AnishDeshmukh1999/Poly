#include "Window.h"

Poly::Window::Window(int v_windowWidth, int v_windowHeight)
{
	windowWidth = v_windowWidth;
	windowHeight = v_windowHeight;
}

Poly::Window::~Window()
{
}

void Poly::Window::glfw_error_callback(int error, const char* description) {
	POLY_ERROR("GLFW Error ({}): {}", error, description);
}

int Poly::Window::Initialize()
{
	glfwSetErrorCallback(glfw_error_callback);
	window = glfwCreateWindow(windowWidth, windowHeight, "PolyEngine", NULL, NULL);
	if (!window) {
		POLY_FATAL("Couldn't create GLFW Window!");
		return false;
	}
	return true;
}

int Poly::Window::Shutdown()
{
	glfwDestroyWindow(window);
	return false;
}

void Poly::Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	POLY_TRACE("In framebuffer size callback");
}

void Poly::Window::keypress_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
}

