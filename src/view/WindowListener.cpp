#include "WindowListener.h"

void WindowListener::readSingleEvent(const sf::Event& event) const {
    switch(event.type) {
        case sf::Event::Closed:
            onClosed();
            break;
        case sf::Event::LostFocus:
            onLostFocus();
            break;
        case sf::Event::GainedFocus:
            onGainedFocus();
            break;
        case sf::Event::KeyPressed:
            onKeyPressed(event.key);
            break;
        case sf::Event::KeyReleased:
            onKeyReleased(event.key);
            break;
        case sf::Event::MouseWheelMoved:
            onMouseWheelMoved(event.mouseWheel);
            break;
        case sf::Event::MouseButtonPressed:
            onMouseButtonPressed(event.mouseButton);
            break;
        case sf::Event::MouseButtonReleased:
            onMouseButtonReleased(event.mouseButton);
            break;
        case sf::Event::MouseMoved:
            onMouseMoved(event.mouseMove);
            break;
        case sf::Event::MouseEntered:
            onMouseEntered();
            break;
        case sf::Event::MouseLeft:
            onMouseLeft();
            break;
        default:
            return;
    }
}

WindowListener::~WindowListener() {
}
