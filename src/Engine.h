#pragma once
#include <memory>


#include "MainWindow.h"
#include "managers/logmanager.h"
#include "log.h"

namespace Poly
{
class Engine
{
public:
	Engine();
	~Engine();
	int Initialize();
	void Render();
	void Shutdown();
private:
	bool m_isRunning = false;
	std::unique_ptr<Poly::managers::LogManager> m_logManager;
	Poly::Window* m_mainWindow;
};
}

