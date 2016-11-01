#include "View.h"

#include <SFML/Graphics/Vertex.hpp>

#include "game_logic/MainLoop.h"
#include "GameConstants.h"
#include "WindowListener.h"
#include "commons/Line.h"
#include "commons/Utility.h"

const sf::Vector2i View::WINDOW{WINDOW_X, WINDOW_Y};
sf::RenderWindow View::window(sf::VideoMode(WINDOW_X, WINDOW_Y), GAME_TITLE);

View::View() : 
        window_listener(nullptr) {
}

View::View(std::unique_ptr<WindowListener> listener) :
        window_listener(std::move(listener)) {
}

View::~View() {
}

void View::setWindowListener(std::unique_ptr<WindowListener> new_listener) {
    std::swap(window_listener, new_listener);
}

const sf::RenderWindow& View::getWindow() {
    return window;
}

void View::drawLine(const Line& l) {
    print(l.begin());
    print(l.end());
    sf::Vertex points[] = {
        sf::Vertex(sf::Vector2f(l.begin()), sf::Color::Blue),
        sf::Vertex(sf::Vector2f(l.end()), sf::Color::Blue)
    };
    window.draw(points, 2, sf::Lines);
}

void View::onUpdate(const BasicEventArgs&) {
    sf::Event event;
    while(window.pollEvent(event) == true) 
        window_listener->readSingleEvent(event);
}

