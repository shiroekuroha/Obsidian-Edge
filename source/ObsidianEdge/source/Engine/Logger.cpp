#include "Engine/Logger.h"

namespace ObsidianEdge
{
	std::shared_ptr<spdlog::logger> Logger::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Logger::s_ClientLogger;

	Logger::Logger()
	{
	}

	Logger::~Logger()
	{
	}

	void Logger::Init()
	{
		spdlog::set_pattern("%^ [%x - %X] [%=9l] %n : %v %$");

		s_CoreLogger = spdlog::stdout_color_mt("Engine");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("Application");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}
