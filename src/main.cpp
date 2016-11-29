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

#include "game_logic/shaders/Shader.h"

#include "controller/Controller.h"
#include "controller/Keyboard.h"

#include <iostream>
#include <cassert>

class KappaView : public View {
    public:
        KappaView(Shape&& s, const Shader& sha) : View(), model(std::move(s), sha), camera(sha) {
            model.connect();
            camera.lean(40);
            camera.setPosition({0, 0, -4});
            
        }
        Model model;
        Camera camera;
        void onUpdate(const BasicEventArgs& args) {
            if(Keyboard::getInstance().isPressed(GLFW_KEY_W))
                camera.move(camera.getDirection()/2.0f);
            if(Keyboard::getInstance().isPressed(GLFW_KEY_S))
                camera.move(camera.getDirection()/-2.0f);
            if(Keyboard::getInstance().isPressed(GLFW_KEY_A))
                camera.move(camera.left()/2.0f);
            if(Keyboard::getInstance().isPressed(GLFW_KEY_D))
                camera.move(camera.right()/2.0f);

            assert(glm::length(camera.right()) -1 <= 0.001f);
        }
        void doDrawing() {
            assert(glm::length(camera.getDirection()) - 1 <= 0.001f);
            camera.begin();
            model.draw();
        }
};

class KappaController : public Controller<KappaView> {
    public:
    KappaController(KappaView& view) : Controller(view) {

    }
    private:
    void onMouseMove(KappaView& context, double x_pos, double y_pos) {
        const auto middle_screen = MainLoop::WINDOW/2;
        glfwSetCursorPos(MainLoop::getInstance().getWindow().get(), middle_screen.x, middle_screen.y);
        const auto diff = Vector2D{x_pos, y_pos} - Vector2D(middle_screen);
        const float sensitivity = 0.1f;
        context.camera.lean(diff.y * sensitivity);
        context.camera.rotate(diff.x * sensitivity);
    }

    void onMouseButtonEvent(KappaView& context, int button, int action, int mods) {
    }

    void onMouseLeave(KappaView& context, int entered) {
    }

    void onKeyEvent(KappaView& context, int key, int scancode, int action, int mods) {
        if(action == GLFW_PRESS) {
            if(key == GLFW_KEY_ENTER or key == GLFW_KEY_ESCAPE)
                MainLoop::getInstance().stop();
            else
                Keyboard::getInstance().press(key);
        } else if(action == GLFW_RELEASE) {
            Keyboard::getInstance().release(key);
        }
    }
};

int main() {
    MainLoop::getInstance();
    Shader shader("shader.vert", "shader.frag");
    
    KappaView view(Shape(table_vertices, table_indices, GL_STATIC_DRAW), shader);
    KappaController controller(view);
    controller.connect();
    view.connect();
    MainLoop::getInstance().start();
}
