#include <GL/glew.h>
#include <GL/gl.h>

#include "game_logic/MainLoop.h"

#include "model/Model.h"

#include "view/GameView.h"

#include "controller/GameController.h"

int main() {
    MainLoop::getInstance();

    Model model;
    GameView view(model);
    GameController controller(view);
    model.connect();
    controller.connect();
    view.connect();
    MainLoop::getInstance().start();
}
