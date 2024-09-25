#include "ObsidianEdge.h"

class Sandbox : public ObsidianEdge::Application
{
public:
	Sandbox()
	{
		OE_INFO("Application Starting...")
	}

	~Sandbox()
	{
		OE_INFO("Application Ending...")
	}

	void Run() {
		
	}

private:
};

ObsidianEdge::Application *ObsidianEdge::CreateApplication()
{
	return new Sandbox;
}
