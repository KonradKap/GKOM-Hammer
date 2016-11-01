#include "MainLoop.h"

#include <iostream>

#include <SFML/System/Clock.hpp>
#include <SFML/System/Sleep.hpp>

MainLoop& MainLoop::getInstance() {
    static MainLoop instance;
    return instance;
}

MainLoop::MainLoop() : 
        running(false) {
}

void MainLoop::connect(
        BasicEventType type, 
        Loopable* caller,
        BasicEvent::callback_function callback) {

    events[size_t(type)].connect(caller, callback);
}

void MainLoop::disconnect(
        BasicEventType type, 
        Loopable* caller,
        BasicEvent::callback_function callback) {

    events[size_t(type)].disconnect(caller, callback);
}

void MainLoop::start() {
    running = true;

    events[size_t(BasicEventType::START)].signal({});

    sf::Clock game_timer;
    sf::Clock frame_timer;

    while( running ) {
        loopOnce(frame_timer, game_timer);
        frame_timer.restart();
    }

    events[size_t(BasicEventType::STOP)].signal({game_timer.getElapsedTime().asMilliseconds()});
}

void MainLoop::stop() {
    running = false;
}

void MainLoop::loopOnce(const sf::Clock& frame_timer, const sf::Clock& game_timer) {
    const int GAME_TIME  = game_timer.getElapsedTime().asMilliseconds();

    events[size_t(BasicEventType::UPDATE)].signal({FRAME_TIME_MSEC});
    events[size_t(BasicEventType::DRAW)].signal({GAME_TIME});

    const int FRAME_TIME = frame_timer.getElapsedTime().asMilliseconds();
//    std::cout << FRAME_TIME_MSEC - FRAME_TIME << std::endl;
    sf::sleep(sf::milliseconds(FRAME_TIME_MSEC - FRAME_TIME));
}

