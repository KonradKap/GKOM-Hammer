 /*
  * EventType.h
  *
  * 2.09.2016 r.
  *
  * Memotosh
  *
  */

#pragma once

#include <chrono>

enum class BasicEventType {
    START = 0,
    UPDATE,
    DRAW,
    PAUSE,
    RESUME,
    STOP,
    COUNT,
};

class BasicEventArgs {
    public:
        std::chrono::milliseconds frame_time;
};
