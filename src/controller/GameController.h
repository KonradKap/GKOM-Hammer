#pragma once

#include "controller/Controller.h"

class GameView;

class GameController : public Controller {
    public:
        GameController(GameView& view);
    private:
        void onMouseMove(double x_pos, double y_pos);
        void onMouseButtonEvent(int button, int action, int mods);
        void onMouseLeave(int entered);
        void onKeyEvent(int key, int scancode, int action, int mods);

        GameView& context;
};
