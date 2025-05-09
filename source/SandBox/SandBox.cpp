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

    void run() override
    {
        OE_INFO("Application Running...")
        Application::run();
    }

private:
};

ObsidianEdge::Application *ObsidianEdge::createApplication()
{
    return new Sandbox;
}
