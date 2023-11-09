#pragma once
#include "Application.h"

extern Poly::Application* Poly::CreateApplication(int argc, char** argv);

GLuint textureID; // This is the ID of the OpenGL texture

// Load an image and create an OpenGL texture
void LoadTexture() {
	// Generate a simple checkerboard pattern (32x32 pixels)
	const int width = 32;
	const int height = 32;
	unsigned char data[width * height * 4];
	for (int i = 0; i < width * height; ++i) {
		int x = i % width;
		int y = i / width;
		data[i * 4] = ((x / 8 + y / 8) & 1) ? 255 : 0;
		data[i * 4 + 1] = ((x / 8 + y / 8) & 1) ? 255 : 0;
		data[i * 4 + 2] = ((x / 8 + y / 8) & 1) ? 255 : 0;
		data[i * 4 + 3] = 255;
	}

	// Generate and bind an OpenGL texture
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

class ViewportLayer : public Poly::Layer
{
public:
	virtual void OnUIRender(GLFWwindow *window) override
	{
		ImGuiIO& io = ImGui::GetIO();
		
		ImGuiWindowFlags window_flags = 0;
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport(), ImGuiDockNodeFlags_PassthruCentralNode);
		window_flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse;
		ImGui::Begin("Background Window", nullptr, window_flags);
		{
			ImGui::ShowDemoWindow();
		}
		ImGui::End();
	}
};

Poly::Application* Poly::CreateApplication(int argc, char** argv) {
	Poly::ApplicationSpecification spec;
	spec.Name = "Walnut Example";

	Poly::Application* app = new Poly::Application(spec);
	app->PushLayer<ViewportLayer>();
	app->SetMenubarCallback([app]()
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Exit"))
				{
					app->Close();
				}
				ImGui::EndMenu();
			}
		});
	return app;
}

namespace Poly {
	int Main(int argc, char** argv) {
		while (g_applicationRunning) {
			Poly::Application* app = Poly::CreateApplication(argc, argv);
			app->Run();
			delete app;
		}
		return 0;
	}
}