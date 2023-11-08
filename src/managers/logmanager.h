#pragma once

namespace Poly::managers
{
	class LogManager {
	public:
		LogManager() = default;
		~LogManager() = default;

		void Initialize();
		void Shutdown();
	};
}