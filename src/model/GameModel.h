#pragma once

class GameController : public Controller {
    public:
    GameController(GameView& view) : Controller(), context(view) {
    }
    private:
    void onMouseMove(double x_pos, double y_pos) {
        const auto middle_screen = MainLoop::WINDOW/2;
        glfwSetCursorPos(MainLoop::getInstance().getWindow().get(), middle_screen.x, middle_screen.y);
        const auto diff = Vector2D{x_pos, y_pos} - Vector2D(middle_screen);
        const float sensitivity = 0.1f;
        context.camera.lean(diff.y * sensitivity);
        context.camera.rotate(diff.x * sensitivity);
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

