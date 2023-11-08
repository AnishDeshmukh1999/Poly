#pragma once

#include<memory>

#include"log.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <GLAD/glad.h>
#include <GLFW/glfw3.h>


namespace Poly {
	struct DestroyglfwWin {

		void operator()(GLFWwindow* ptr) {
			glfwDestroyWindow(ptr);
		}

	};

	class Window
	{
	public:
		Window(int v_windowWidth, int v_windowHeight);
		~Window();
		virtual int Initialize();
		int Shutdown();
		GLFWwindow* window = nullptr;
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
		virtual void processInput() = 0;
		static void keypress_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void glfw_error_callback(int error, const char* description);

	private:
		int windowWidth;
		int windowHeight;

	};
}

