#include "MainLoop.h"

#include <SFML/System/Clock.hpp>

MainLoop& MainLoop::getInstance() {
    static MainLoop instance;
    return instance;
}

MainLoop::MainLoop() : 
        running(false) {
}

void MainLoop::connect(
        BasicEventType type, 
        std::function<void (const BasicEventArgs&)> callback) {

    events[size_t(type)].connect(callback);
}

void MainLoop::disconnect(
        BasicEventType type, 
        std::function<void (const BasicEventArgs&)> callback) {

    events[size_t(type)].disconnect(callback);
}

void MainLoop::start() {
    running = true;

    events[size_t(BasicEventType::START)].signal({0});

    sf::Clock game_timer;
    
    for(sf::Clock frame_timer; running; frame_timer.restart()) {
        loopOnce(
            frame_timer.getElapsedTime().asMilliseconds(),
            game_timer.getElapsedTime().asMilliseconds());
    }

    events[size_t(BasicEventType::STOP)].signal({game_timer.getElapsedTime().asMilliseconds()});
}

void MainLoop::stop() {
    running = false;
}

void MainLoop::loopOnce(int frame_time, int game_time) {
    events[size_t(BasicEventType::UPDATE)].signal({frame_time});
    events[size_t(BasicEventType::DRAW)].signal({game_time});
}

