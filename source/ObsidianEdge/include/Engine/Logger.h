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

		static void init();

		static std::shared_ptr<spdlog::logger> &getCoreLogger() { return s_coreLogger; };
		static std::shared_ptr<spdlog::logger> &getClientLogger() { return s_clientLogger; };

	private:
		static std::shared_ptr<spdlog::logger> s_coreLogger;
		static std::shared_ptr<spdlog::logger> s_clientLogger;
	};
}

#ifdef OE_DEBUG

#define OE_CORE_TRACE(...)  ::ObsidianEdge::Logger::getCoreLogger()->trace(__VA_ARGS__);
#define OE_CORE_INFO(...)   ::ObsidianEdge::Logger::getCoreLogger()->info(__VA_ARGS__);
#define OE_CORE_WARN(...)   ::ObsidianEdge::Logger::getCoreLogger()->warn(__VA_ARGS__);
#define OE_CORE_ERROR(...)  ::ObsidianEdge::Logger::getCoreLogger()->error(__VA_ARGS__);
#define OE_CORE_FATAL(...)  ::ObsidianEdge::Logger::getCoreLogger()->fatal(__VA_ARGS__);

#define OE_TRACE(...)       ::ObsidianEdge::Logger::getClientLogger()->trace(__VA_ARGS__);
#define OE_INFO(...)        ::ObsidianEdge::Logger::getClientLogger()->info(__VA_ARGS__);
#define OE_WARN(...)        ::ObsidianEdge::Logger::getClientLogger()->warn(__VA_ARGS__);
#define OE_ERROR(...)       ::ObsidianEdge::Logger::getClientLogger()->error(__VA_ARGS__);
#define OE_FATAL(...)       ::ObsidianEdge::Logger::getClientLogger()->fatal(__VA_ARGS__);

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