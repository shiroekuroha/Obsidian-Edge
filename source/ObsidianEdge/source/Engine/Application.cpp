#include "Engine/Application.h"

namespace ObsidianEdge
{
	Application::Application()
	{
		OE_CORE_TRACE("Application Constructed!")
	}

	Application::~Application()
	{
		OE_CORE_WARN("Application Deconstructed!")
	}

	void Application::Run()
	{
		while(true);
	}
}