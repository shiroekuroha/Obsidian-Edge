#ifndef OE_APPLICATION_H
#define OE_APPLICATION_H

#include "Logger/Logger.h"

namespace ObsidianEdge
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
	};

	Application *CreateApplication();

}

#endif