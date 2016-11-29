#pragma once

#include <array>

#include <GLFW/glfw3.h>

class Keyboard {
    public:
        static Keyboard& getInstance();

        bool isPressed(int key) const;
        void press(int key);
        void release(int key);

    private:
        Keyboard();
        Keyboard(const Keyboard& k) = delete;
        Keyboard& operator=(Keyboard k) = delete;

        std::array<bool, GLFW_KEY_LAST+1> keys;
};
