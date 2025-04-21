#ifndef OE_APPLICATION_H
#define OE_APPLICATION_H

#include "Engine/Core/Logger.h"
#include "Engine/Core/Window.h"
#include "Engine/Events/ApplicationEvent.h"

namespace ObsidianEdge
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void onEvent(Event& e);
		virtual void run();

	private:
		bool onWindowClose(WindowClosedEvent& e);
	
		std::unique_ptr<Window> m_window;
		bool m_running = true;
	};

	Application *createApplication();
}

#endif