#pragma once

#include "game_logic/Loopable.h"
#include "view/Window.h"
#include "view/WindowListener.h"

class Model;
class BasicEventArgs;

class View : public LoopableAdapter {
    public:
        View();
        View(const View& view) = delete;
        View(WindowListener listener);
        virtual ~View();

        void setWindowListener(WindowListener new_listener);
    private:
        void onDraw(const BasicEventArgs& args);
        virtual void doDrawing() = 0;
        void onStart(const BasicEventArgs&);
        void setWindowCallbacks(GLFWwindow* window);

        WindowListener window_listener;
};
