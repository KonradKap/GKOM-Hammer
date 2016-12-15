#include <GL/glew.h>
#include <GL/gl.h>

#include "game_logic/MainLoop.h"
#include "game_logic/exceptions/OpenGlException.h"

#include "view/WindowListener.h"
#include "view/View.h"
#include "view/Camera.h"

#include "commons/Vector2.h"
#include "commons/Utility.h"
#include "commons/ScopeBind.h"

#include "model/Model.h"
#include "model/BasicShapes.h"

#include "view/Shader.h"
#include "view/Light.h"
#include "view/GameView.h"

#include "controller/Controller.h"
#include "controller/Keyboard.h"

class KappaController : public Controller {
    public:
    KappaController(GameView& view) : Controller(), context(view) {
    }
    private:
    void onMouseMove(double x_pos, double y_pos) {
        const auto middle_screen = MainLoop::WINDOW/2;
        glfwSetCursorPos(MainLoop::getInstance().getWindow().get(), middle_screen.x, middle_screen.y);
        const auto diff = Vector2D{x_pos, y_pos} - Vector2D(middle_screen);
        const float sensitivity = 0.1f;
        context.getCamera().lean(diff.y * sensitivity);
        context.getCamera().rotate(diff.x * sensitivity);
    }

    void onMouseButtonEvent(int button, int action, int mods) {
    }

    void onMouseLeave(int entered) {
    }

    void onKeyEvent(int key, int scancode, int action, int mods) {
        if(action == GLFW_PRESS and (key == GLFW_KEY_ENTER or key == GLFW_KEY_ESCAPE))
            MainLoop::getInstance().stop();
    }

    GameView& context;
};

int main() {
    MainLoop::getInstance();

    Model m;
    m.connect();
    GameView view(m);
    KappaController controller(view);
    controller.connect();
    view.connect();
    MainLoop::getInstance().start();
}
