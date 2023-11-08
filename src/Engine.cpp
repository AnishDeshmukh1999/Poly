#include "Engine.h"

Poly::Engine::Engine()
{
	m_logManager = std::make_unique<Poly::managers::LogManager>();
	m_mainWindow = new Poly::MainWindow(640, 480);
}

Poly::Engine::~Engine()
{
	delete m_mainWindow;
}

int Poly::Engine::Initialize()
{
	m_isRunning = true;

	m_logManager->Initialize();
	POLY_INFO("PolyEngine v{}.{}", 0, 1);

	if (!glfwInit()) {
		POLY_FATAL("GLFW Init failed! Cannot start application!!");
		return -1;
	}


	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	// Set GLFW Error callback
	glfwSetErrorCallback(Poly::Window::glfw_error_callback);


	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // IF using Docking Branch


	int res = m_mainWindow->Initialize();
	if (res != 0) {
		return false;
	}
	glfwMakeContextCurrent(m_mainWindow->window);
	//gladLoadGL();

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		POLY_FATAL("Failed to initialize GLAD");
		return -1;
	}

	// Setup Platform/Renderer backends
	ImGui_ImplGlfw_InitForOpenGL(m_mainWindow->window, true);          // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
	ImGui_ImplOpenGL3_Init();

	return 0;
}

void Poly::Engine::Render()
{
	POLY_TRACE("In Render");
	int i = 0;
	while (!glfwWindowShouldClose(m_mainWindow->window))
	{
		m_mainWindow->processInput();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(m_mainWindow->window);
		glfwPollEvents();
	}

	glfwDestroyWindow(m_mainWindow->window);
}

void Poly::Engine::Shutdown()
{
	POLY_INFO("Shutting down PolyEngine... ");

	glfwTerminate();

	// This should be changed by user in the application
	m_isRunning = false;
	//

	m_logManager->Shutdown();
}
