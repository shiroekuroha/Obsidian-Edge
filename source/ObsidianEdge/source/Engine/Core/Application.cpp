#include "Engine/Core/Application.h"

namespace ObsidianEdge
{
    Application::Application()
    {
        m_window = std::unique_ptr<Window>(Window::create());
        m_window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));
        m_running = true;
    }

    Application::~Application()
    {
    }

    void Application::onEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.dispatch<WindowClosedEvent>(std::bind(&Application::onWindowClose, this, std::placeholders::_1));
    }

    void Application::run()
    {
        int r = 0, g = 0, b = 0;

        while (m_running)
        {
            r = (r + 1) % 255;
            g = (g + 2) % 255;
            b = (b + 3) % 255;
            
            glClearColor((float)r / 255.0f, (float)g / 255.0f, (float)b / 255.0f, 0.20f);
            glClear(GL_COLOR_BUFFER_BIT);

            m_window->onUpdate();
        }
    }

    bool Application::onWindowClose(WindowClosedEvent& e)
    {
        m_running = false;

        return true;
    }
}
