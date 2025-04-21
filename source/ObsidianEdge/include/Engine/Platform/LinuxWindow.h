#ifndef OE_LINUX_WINDOW_H
#define OE_LINUX_WINDOW_H

#include "Engine/Core/Window.h"

#include "Engine/Events/ApplicationEvent.h"
#include "Engine/Events/KeyEvent.h"
#include "Engine/Events/MouseEvent.h"

namespace ObsidianEdge
{
    class LinuxWindow : public Window
    {
    public:
        LinuxWindow(const WindowProps &props = WindowProps());
        virtual ~LinuxWindow() override;

        /**
         * To be implemented when doing multi-platform instructions
         */
    };
}

#endif