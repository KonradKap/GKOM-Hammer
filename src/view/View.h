#pragma once

#include "game_logic/Loopable.h"
#include "view/Window.h"
#include "view/WindowListener.h"

class Model;
class BasicEventArgs;

class View : public LoopableAdapter {
    public:
        View();
        View(const View& view) = default;
        virtual ~View();
    private:
        void onDraw(const BasicEventArgs& args);
        virtual void doDrawing() = 0;
        void onStart(const BasicEventArgs&);
};
