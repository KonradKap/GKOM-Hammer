 /*
  * EventType.h
  *
  * 2.09.2016 r.
  *
  * Memotosh
  *
  */

#pragma once

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
        int frame_time;
};
