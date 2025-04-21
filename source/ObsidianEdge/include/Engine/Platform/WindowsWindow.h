#ifndef OE_WINDOWS_WINDOW_H
#define OE_WINDOWS_WINDOW_H

#include "Engine/Core/Window.h"

#include "Engine/Events/ApplicationEvent.h"
#include "Engine/Events/KeyEvent.h"
#include "Engine/Events/MouseEvent.h"

namespace ObsidianEdge
{
    class WindowsWindow: public Window
    {
    public:
        WindowsWindow(const WindowProps& props);
        virtual ~WindowsWindow() override;

        /**
         * To be implemented when doing multi-platform instructions
         */
    };
}

#endif