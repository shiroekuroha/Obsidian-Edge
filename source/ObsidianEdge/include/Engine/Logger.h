#ifndef OE_LOGGER_H
#define OE_LOGGER_H

#include <memory>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include "Core.h"

namespace ObsidianEdge
{
	class OE_API Logger
	{
	public:
		Logger();
		~Logger();

		static void Init();

		static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; };
		static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; };

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#ifdef OE_DEBUG

#define OE_CORE_TRACE(...) ::ObsidianEdge::Logger::GetCoreLogger()->trace(__VA_ARGS__);
#define OE_CORE_INFO(...) ::ObsidianEdge::Logger::GetCoreLogger()->info(__VA_ARGS__);
#define OE_CORE_WARN(...) ::ObsidianEdge::Logger::GetCoreLogger()->warn(__VA_ARGS__);
#define OE_CORE_ERROR(...) ::ObsidianEdge::Logger::GetCoreLogger()->error(__VA_ARGS__);
#define OE_CORE_FATAL(...) ::ObsidianEdge::Logger::GetCoreLogger()->fatal(__VA_ARGS__);

#define OE_TRACE(...) ::ObsidianEdge::Logger::GetClientLogger()->trace(__VA_ARGS__);
#define OE_INFO(...) ::ObsidianEdge::Logger::GetClientLogger()->info(__VA_ARGS__);
#define OE_WARN(...) ::ObsidianEdge::Logger::GetClientLogger()->warn(__VA_ARGS__);
#define OE_ERROR(...) ::ObsidianEdge::Logger::GetClientLogger()->error(__VA_ARGS__);
#define OE_FATAL(...) ::ObsidianEdge::Logger::GetClientLogger()->fatal(__VA_ARGS__);

#else

#define OE_CORE_TRACE(...)
#define OE_CORE_INFO(...)
#define OE_CORE_WARN(...)
#define OE_CORE_ERROR(...)
#define OE_CORE_FATAL(...)

#define OE_TRACE(...)
#define OE_INFO(...)
#define OE_WARN(...)
#define OE_ERROR(...)
#define OE_FATAL(...)

#endif

#endif