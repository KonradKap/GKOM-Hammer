#include "View.h"

#include "game_logic/MainLoop.h"
#include "WindowListener.h"

View::View() {
}

View::~View() {
}

void View::onStart(const BasicEventArgs&) {
}

void View::onDraw(const BasicEventArgs&) {
    glClearColor(0.0, 0.8, 0.3, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    doDrawing();

    glfwSwapBuffers(MainLoop::getInstance().getWindow().get());
}

