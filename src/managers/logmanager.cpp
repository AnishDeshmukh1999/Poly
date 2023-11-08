#include "logmanager.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"


namespace Poly::managers {
	void LogManager::Initialize()
	{
		auto consoleSink = std::make_shared<spdlog::sinks::stderr_color_sink_mt>();
		consoleSink->set_pattern("%^[%m-%d-%Y %H:%M:%s.%e] %v%$");

		std::vector<spdlog::sink_ptr> sinks{ consoleSink };
		auto logger = std::make_shared<spdlog::logger>("PolyLogger", sinks.begin(), sinks.end());
		logger->set_level(spdlog::level::trace);
		logger->flush_on(spdlog::level::trace);
		spdlog::register_logger(logger);

	}

	void LogManager::Shutdown()
	{
		spdlog::shutdown();
	}
}
