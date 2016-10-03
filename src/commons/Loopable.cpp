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
            this,
            &Loopable::onStart);
    instance.connect(
            BasicEventType::STOP,
            this,
            &Loopable::onStop);
    instance.connect(
            BasicEventType::UPDATE,
            this,
            &Loopable::onUpdate);
    instance.connect(
            BasicEventType::PAUSE, 
            this,
            &Loopable::onPause);
    instance.connect(
            BasicEventType::RESUME, 
            this,
            &Loopable::onResume);
}

void Loopable::disconnect() {
    auto& instance = MainLoop::getInstance();

    instance.disconnect(
            BasicEventType::START, 
            this,
            &Loopable::onStart);
    instance.disconnect(
            BasicEventType::STOP, 
            this,
            &Loopable::onStop);
    instance.disconnect(
            BasicEventType::UPDATE, 
            this,
            &Loopable::onUpdate);
    instance.disconnect(
            BasicEventType::PAUSE, 
            this,
            &Loopable::onPause);
    instance.disconnect(
            BasicEventType::RESUME, 
            this,
            &Loopable::onResume);
}

LoopableAdapter::LoopableAdapter() :
        Loopable() {
}

LoopableAdapter::~LoopableAdapter() {
}

