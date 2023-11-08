#pragma once
#include "Window.h"
namespace Poly {
	class MainWindow : public Window
	{
	public:
		MainWindow(int windowWidth, int windowHeight) : Window(windowWidth, windowHeight) {};
		void processInput();
		int Initialize() override;
		static void keypress_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	};
}

