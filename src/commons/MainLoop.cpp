#include "commons/MainLoop.h"

MainLoop& MainLoop::getInstance() {
    static MainLoop instance;
    return instance;
}

void start();
void pause();
void resume();
void exit();

void MainLoop::LoopablesManager::moveLoopable(
        MainLoop::Container& from, 
        MainLoop::Container& to, 
        std::shared_ptr<Loopable> loopable) {
    from.erase(loopable);
    to.insert(loopable);
}

void MainLoop::LoopablesManager::insertLoopable(
        MainLoop::Container& to,
        std::shared_ptr<Loopable> loopable) {
    to.insert(loopable);
}

void MainLoop::LoopablesManager::deleteLoopable(
        MainLoop::Containter& from,
        std::shared_ptr<Loopable> loopable) {
    from.erase(loopable);
}

void MainLoop::loopOnce() {
    
}


MainLoop();
