#include "Loopable.h"
#include "MainLoop.h"
#include "event/Event.h"
#include "event/EventType.h"

using namespace std::placeholders;

Loopable::~Loopable() {
}

void Loopable::connect() {
    auto& instance = MainLoop::getInstance();

    instance.connect(
            BasicEventType::START, 
            std::bind(&Loopable::onStart, this, _1));
    instance.connect(
            BasicEventType::STOP, 
            std::bind(&Loopable::onStop, this, _1));
    instance.connect(
            BasicEventType::UPDATE, 
            std::bind(&Loopable::onUpdate, this, _1));
    instance.connect(
            BasicEventType::PAUSE, 
            std::bind(&Loopable::onPause, this, _1));
    instance.connect(
            BasicEventType::RESUME, 
            std::bind(&Loopable::onResume, this, _1));
}

void Loopable::disconnect() {
    auto& instance = MainLoop::getInstance();

    instance.disconnect(
            BasicEventType::START, 
            std::bind(&Loopable::onStart, this, _1));
    instance.disconnect(
            BasicEventType::STOP, 
            std::bind(&Loopable::onStop, this, _1));
    instance.disconnect(
            BasicEventType::UPDATE, 
            std::bind(&Loopable::onUpdate, this, _1));
    instance.disconnect(
            BasicEventType::PAUSE, 
            std::bind(&Loopable::onPause, this, _1));
    instance.disconnect(
            BasicEventType::RESUME, 
            std::bind(&Loopable::onResume, this, _1));
}

LoopableAdapter::LoopableAdapter() :
        Loopable() {
}

LoopableAdapter::~LoopableAdapter() {
}

