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

class MainLoop {
    public:
        static MainLoop& getInstance();
        
        void connect(
                BasicEventType type, 
                std::function<void (const BasicEventArgs&)> callback);
        void disconnect(
                BasicEventType type, 
                std::function<void (const BasicEventArgs&)> callback);

        void start();
        void stop();
    private:
        void loopOnce(int frame_time, int game_time);

        MainLoop();
        MainLoop(const MainLoop&) = delete;
    
        bool running;

        std::array<
            Event, 
            size_t(BasicEventType::COUNT)
        > events;
};
