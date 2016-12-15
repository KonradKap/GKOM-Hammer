#pragma once

#include <string>
#include <memory>
#include <deque>

#include <GLFW/glfw3.h>

#include "commons/Vector2.h"
#include "game_logic/event/EventType.h"
#include "game_logic/event/Event.h"

class Window {
    public:
        Window();
        Window(int x_size, int y_size, const std::string& title);
        Window(const Window& w);
        Window(Window&& w);
        
        Window& operator=(Window w);

        ~Window();

        friend void swap(Window& lhs, Window& rhs);

        int getWidth() const;
        int getHeight() const;
        Vector2I getSize() const;
        const std::string& getTitle() const;

        const GLFWwindow* get() const;
        GLFWwindow* get();
    private:

        std::string title;
        std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)> window;
};
