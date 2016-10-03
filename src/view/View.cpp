#include "View.h"

#include "../game_logic/MainLoop.h"
#include "../GameConstants.h"
#include "WindowListener.h"

View::View() : 
        window(sf::VideoMode(WINDOW_X, WINDOW_Y), GAME_TITLE),
        window_listener(nullptr) {
}

View::~View() {
}

void View::setWindowListener(std::unique_ptr<WindowListener> new_listener) {
    std::swap(window_listener, new_listener);
}

void View::onUpdate(const BasicEventArgs&) {
    sf::Event event;
    while(window.pollEvent(event) == true) 
        window_listener->readSingleEvent(event);
}

