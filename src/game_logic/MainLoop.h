 /*
  * MainLoop,h
  *
  * 2.09.2016 r.
  *
  * Memotosh
  */

#pragma once

#include <functional>

#include "event/EventType.h"
#include "event/Event.h"
#include "Loopable.h"

namespace sf {
    class Clock;
} //namespace sf

typedef Event<Loopable, const BasicEventArgs&> BasicEvent;

class MainLoop {
    public:
        constexpr static const int TARGET_FPS  = 60;
        constexpr static const double TARGET_FPMS = TARGET_FPS / 1000.;
        constexpr static const double FRAME_TIME_SEC = 1. / TARGET_FPS;
        constexpr static const int FRAME_TIME_MSEC = 1 / TARGET_FPMS;

        static MainLoop& getInstance();
        
        void connect(
                BasicEventType type, 
                Loopable* caller,
                BasicEvent::callback_function callback);
        void disconnect(
                BasicEventType type,
                Loopable* caller,
                BasicEvent::callback_function callback);

        void start();
        void stop();
    private:
        void loopOnce(const sf::Clock& frame_time, const sf::Clock& game_time);

        MainLoop();
        MainLoop(const MainLoop&) = delete;
    
        bool running;

        std::array<
            BasicEvent,
            size_t(BasicEventType::COUNT)
        > events;
};
