#ifndef OE_OBSIDIAN_EDGE_H
#define OE_OBSIDIAN_EDGE_H

#define GLFW_INCLUDE_NONE

#include "Core.h"

namespace ObsidianEdge
{
	class OE_API Engine
	{
	public:
		Engine();
		virtual ~Engine();

	#ifdef DEBUG
		void test();
	#endif

	private:
	};
}
#endif