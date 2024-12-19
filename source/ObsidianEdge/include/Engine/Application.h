#ifndef OE_APPLICATION_H
#define OE_APPLICATION_H

#include "Logger.h"

namespace ObsidianEdge
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void run();

	private:
	};

	Application *createApplication();
}

#endif
