#include "MainWindow.h"

void Poly::MainWindow::processInput() {
}

int Poly::MainWindow::Initialize()
{
	Window::Initialize();
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetKeyCallback(window, keypress_callback);
	return 0;
}

void Poly::MainWindow::keypress_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	POLY_TRACE("Key: {} Scancode: {} Action: {}, Mods: {}", key, scancode, action, mods);
}
