#include "controller/Keyboard.h"

Keyboard& Keyboard::getInstance() {
    static Keyboard instance;
    return instance;
}

bool Keyboard::isPressed(int key) const {
    return keys[key];
}

void Keyboard::press(int key) {
    keys[key] = true;
}

void Keyboard::release(int key) {
    keys[key] = false;
}
        
Keyboard::Keyboard() : 
        keys() {

    keys.fill(false);
}
