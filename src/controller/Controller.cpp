#include "Controller.h"

#include <GLFW/glfw3.h>

#include "game_logic/MainLoop.h"
#include "controller/Keyboard.h"

Controller::Controller() {
}


Controller::Controller(const Controller& c) {
}


Controller::~Controller() {
}


void Controller::connect() {
    auto window = MainLoop::getInstance().getWindow().get();
    setWindowCallbacks(window);
    glfwSetWindowUserPointer(window, this);
}


void Controller::disconnect() {
    //TODO
}


void Controller::mouse_move_cb(GLFWwindow* window, double x, double y) {
    auto message = static_cast<Controller*>(glfwGetWindowUserPointer(window));
    message->onMouseMove(x, y);
}


void Controller::mouse_button_cb(GLFWwindow* window, int button, int action, int mods) {
    auto message = static_cast<Controller*>(glfwGetWindowUserPointer(window));
    message->onMouseButtonEvent(button, action, mods);
}


void Controller::mouse_leave_cb(GLFWwindow* window, int entered) {
    auto message = static_cast<Controller*>(glfwGetWindowUserPointer(window));
    message->onMouseLeave(entered);
}


void Controller::key_button_cb(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if(action == GLFW_PRESS) {
        Keyboard::getInstance().press(key);
    } else if(action == GLFW_RELEASE) {
        Keyboard::getInstance().release(key);
    }
    auto message = static_cast<Controller*>(glfwGetWindowUserPointer(window));
    message->onKeyEvent(key, scancode, action, mods);
}

void Controller::setWindowCallbacks(GLFWwindow* window) {
    glfwSetKeyCallback(window, Controller::key_button_cb);
    glfwSetMouseButtonCallback(window, Controller::mouse_button_cb);
    glfwSetCursorPosCallback(window, Controller::mouse_move_cb);
    glfwSetCursorEnterCallback(window, Controller::mouse_leave_cb);
}
