#include "View.h"

#include "game_logic/MainLoop.h"
#include "WindowListener.h"

View::View() : 
        window_listener() {
}

View::View(WindowListener listener) :
        window_listener(listener) {
}

View::~View() {
}

void View::onStart(const BasicEventArgs&) {
    setWindowCallbacks(MainLoop::getInstance().getWindow().get());
}

void View::onDraw(const BasicEventArgs&) {
    glClearColor(0.0, 0.8, 0.3, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    doDrawing();

    glfwSwapBuffers(MainLoop::getInstance().getWindow().get());
}

void View::setWindowListener(WindowListener new_listener) {
    std::swap(window_listener, new_listener);
    auto window = MainLoop::getInstance().getWindow().get();
    if(window)
        setWindowCallbacks(window);
}

void View::setWindowCallbacks(GLFWwindow* window) {
    glfwSetKeyCallback(window, window_listener.key_callback);
    glfwSetMouseButtonCallback(window, window_listener.mouse_button_callback);
    glfwSetCursorPosCallback(window, window_listener.cursor_pos_callback);
    glfwSetCursorEnterCallback(window, window_listener.cursor_enter_callback);
}
