#include "Window.h"

#include "game_logic/exceptions/OpenGlException.h"

Window::Window() :
        title(),
        window(nullptr, glfwDestroyWindow) {

}

Window::Window(int x_size, int y_size, const std::string& title) :
        title(title),
        window(glfwCreateWindow(x_size, y_size, title.c_str(), nullptr, nullptr), glfwDestroyWindow) {
 
    if(!window)
        throw OpenGlException("Window creation failed");
}

Window::Window(const Window& w) :
        Window(w.getWidth(), w.getHeight(), w.getTitle()) {

}

Window::Window(Window&& w) :
        Window() {

    swap(*this, w);
}

Window& Window::operator=(Window w) {
    swap(*this, w);
    return *this;
}

Window::~Window() {
}

void swap(Window& lhs, Window& rhs) {
    std::swap(lhs.window, rhs.window);
    std::swap(lhs.title, rhs.title);
}

int Window::getWidth() const {
    return getSize().x;
}

int Window::getHeight() const {
    return getSize().y;
}

Vector2I Window::getSize() const {
    Vector2I ret;
    glfwGetWindowSize(window.get(), &(ret.x), &(ret.y));
    return ret;
}

const std::string& Window::getTitle() const {
    return title;
}

const GLFWwindow* Window::get() const {
    return window.get();
}

GLFWwindow* Window::get() {
    return const_cast<GLFWwindow*>(static_cast<const Window*>(this)->get());
}
