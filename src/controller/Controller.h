#pragma once

struct GLFWwindow;

class Controller {
    public:
        Controller();
        Controller(const Controller& c);
        virtual ~Controller();

        void connect();
        void disconnect();
    private:
        virtual void onMouseMove(double x_pos, double y_pos) = 0;
        virtual void onMouseButtonEvent(int button, int action, int mods) = 0;
        virtual void onMouseLeave(int entered) = 0;
        virtual void onKeyEvent(int key, int scancode, int action, int mods) = 0;

        static void mouse_move_cb(GLFWwindow* window, double x, double y);
        static void mouse_button_cb(GLFWwindow* window, int button, int action, int mods);
        static void mouse_leave_cb(GLFWwindow* window, int entered);
        static void key_button_cb(GLFWwindow* window, int key, int scancode, int action, int mods);
        void setWindowCallbacks(GLFWwindow* window);
};
