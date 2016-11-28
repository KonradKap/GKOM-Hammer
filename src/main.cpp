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

class KappaView : public View {
    public:
        KappaView(Shape&& s, const Shader& sha) : View(), model(std::move(s), sha), camera(sha) {
            model.connect();
        }
    private:
        Model model;
        Camera camera;
        void doDrawing() {
            camera.move({0.0f, 0.01f, -0.01f});
            camera.begin();
            model.draw();
        }
};

void kappa_mouse_b(GLFWwindow *, int, int, int) {
}

void kappa_cursor_p(GLFWwindow *, double, double) {
}

void kappa_cursor_e(GLFWwindow *, int) {
}

void kappa_key_fun(GLFWwindow *, int key, int, int s, int) {
    if(key == GLFW_KEY_ESCAPE and s == GLFW_PRESS) 
        MainLoop::getInstance().stop();
}

int main() {
    MainLoop::getInstance();
    Shader shader("shader.vert", "shader.frag");
    
    KappaView view(Shape(table_vertices, table_indices, GL_STATIC_DRAW), shader);
    view.setWindowListener({&kappa_key_fun, &kappa_mouse_b, &kappa_cursor_p, &kappa_cursor_e});
    view.connect();
    MainLoop::getInstance().start();
}
