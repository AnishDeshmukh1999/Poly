#pragma once
#include "Application.h"

extern Poly::Application* Poly::CreateApplication(int argc, char** argv);


class ExampleLayer : public Poly::Layer
{
public:
	virtual void OnUIRender() override
	{

	}
};

Poly::Application* Poly::CreateApplication(int argc, char** argv) {
	Poly::ApplicationSpecification spec;
	spec.Name = "Walnut Example";

	Poly::Application* app = new Poly::Application(spec);
	app->PushLayer<ExampleLayer>();
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