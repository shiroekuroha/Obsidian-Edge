#ifndef OE_WINDOWS_H
#define OE_WINDOWS_H

#include <memory>

#include "GLFW/glfw3.h"

#include "Engine/Core/Core.h"
#include "Engine/Core/Logger.h"
#include "Engine/Events/Event.h"

namespace ObsidianEdge
{
    extern void setGLFWInitialized(bool init);
    extern bool isGLFWInitialized();

    struct WindowProps
    {
        std::string title;
        uint32_t width;
        uint32_t height;

        WindowProps(const std::string &title = "Obsidian Edge", uint32_t width = 1600, uint32_t height = 900)
            : title(title), width(width), height(height)
        {
        }
    };

    class Window
    {
    public:
        using EventCallbackFn = std::function<void(Event &)>;

        Window(const WindowProps& props);
        virtual ~Window();

        virtual void onUpdate();

        virtual uint32_t getWidth() const;
        virtual uint32_t getHeight() const;

        virtual void setEventCallback(const EventCallbackFn &callback);
        virtual void setVSync(bool enabled);
        virtual bool isVSync() const;

        static Window *create(const WindowProps &props = WindowProps());

    private:
        struct WindowData
        {
            std::string title;
            unsigned int width, height;
            bool vSync;

            EventCallbackFn eventCallback;
        };

        GLFWwindow *m_window;
        WindowData m_data;
    };
}

#endif