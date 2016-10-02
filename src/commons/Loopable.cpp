#include "commons/Loopable.h"
#include "commons/MainLoop.h"
#include "commons/EventUtils.h"

void Loopable::Loopable() : 
    id(-1) {
    }

virtual ~Loopable() {
}

void Loopable::pause() {
    id = MainLoop::getInstance().pauseLoopable(id);
    onPause(EventArgs{});
}

void Loopable::resume() {
    id = MainLoop::getInsance().resumeLoopable(id);
    onResume(EventArgs{});
}

void Loopable::stop() {
    MainLoop::getInstance().stopLoopable(id);
    onStop(EventArgs{});
}

void Loopable::start() {
    id = MainLoop::getInstance().startLoopable(this);
    onStart(EventArgs{});
}


