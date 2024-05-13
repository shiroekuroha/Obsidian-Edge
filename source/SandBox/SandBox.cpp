#include "ObsidianEdge.h"

class Sandbox : public ObsidianEdge::Application
{
public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}

private:
};

ObsidianEdge::Application *ObsidianEdge::CreateApplication()
{
	return new Sandbox;
}