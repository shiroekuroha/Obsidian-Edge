#include "Engine/Core/Logger.h"

namespace ObsidianEdge
{
	std::shared_ptr<spdlog::logger> Logger::s_coreLogger;
	std::shared_ptr<spdlog::logger> Logger::s_clientLogger;

	Logger::Logger()
	{
	}

	Logger::~Logger()
	{
	}

	void Logger::init()
	{
		spdlog::set_pattern("%^ [%x - %X] [%=9l] %n : %v %$");

		s_coreLogger = spdlog::stdout_color_mt("Engine");
		s_coreLogger->set_level(spdlog::level::trace);

		s_clientLogger = spdlog::stdout_color_mt("Application");
		s_clientLogger->set_level(spdlog::level::trace);
	}
}
