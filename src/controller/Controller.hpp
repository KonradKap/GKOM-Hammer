
#include <GLFW/glfw3.h>

#include "game_logic/MainLoop.h"

template<class Context>
    Controller<Context>::Controller(Context& c) : 
            message({c, this}) {
    
    }

template<class Context>
    Controller<Context>::Controller(const Controller& c) : 
            message({const_cast<Context&>(c.message.context), this}) {

    }

template<class Context>
    Controller<Context>::~Controller() {
    }

template<class Context>
    void Controller<Context>::connect() {
        auto window = MainLoop::getInstance().getWindow().get();
        setWindowCallbacks(window);
        glfwSetWindowUserPointer(window, &message);
    }

template<class Context>
    void Controller<Context>::disconnect() {
        //TODO
    }

template<class Context>
    void Controller<Context>::mouse_move_cb(GLFWwindow* window, double x, double y) {
        auto message = static_cast<Message*>(glfwGetWindowUserPointer(window));
        message->this_->onMouseMove(message->context, x, y);
    }

template<class Context>
    void Controller<Context>::mouse_button_cb(GLFWwindow* window, int button, int action, int mods) {
        auto message = static_cast<Message*>(glfwGetWindowUserPointer(window));
        message->this_->onMouseButtonEvent(message->context, button, action, mods);
    }

template<class Context>
    void Controller<Context>::mouse_leave_cb(GLFWwindow* window, int entered) {
        auto message = static_cast<Message*>(glfwGetWindowUserPointer(window));
        message->this_->onMouseLeave(message->context, entered);
    }

template<class Context>
    void Controller<Context>::key_button_cb(GLFWwindow* window, int key, int scancode, int action, int mods) {
        auto message = static_cast<Message*>(glfwGetWindowUserPointer(window));
        message->this_->onKeyEvent(message->context, key, scancode, action, mods);
    }

template<class Context>
    void Controller<Context>::setWindowCallbacks(GLFWwindow* window) {
        glfwSetKeyCallback(window, Controller::key_button_cb);
        glfwSetMouseButtonCallback(window, Controller::mouse_button_cb);
        glfwSetCursorPosCallback(window, Controller::mouse_move_cb);
        glfwSetCursorEnterCallback(window, Controller::mouse_leave_cb);
    }
