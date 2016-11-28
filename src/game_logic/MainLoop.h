 /*
  * MainLoop,h
  *
  * 2.09.2016 r.
  *
  * Memotosh
  */

#pragma once

#include <functional>
#include <chrono>

#include "event/EventType.h"
#include "event/Event.h"
#include "Loopable.h"
#include "view/Window.h"
#include "commons/Vector2.h"

typedef Event<Loopable, const BasicEventArgs&> BasicEvent;

class MainLoop {
    public:
        constexpr static const int WINDOW_X = 800;
        constexpr static const int WINDOW_Y = 640;
        static const Vector2I WINDOW;

        constexpr static const auto TARGET_FPS = 60;
        constexpr static const auto TARGET_FPMS = TARGET_FPS / 1000.;
        constexpr static const auto FRAME_TIME_SEC = std::chrono::seconds(1) / TARGET_FPS;
        constexpr static const auto FRAME_TIME_MSEC = std::chrono::milliseconds(1) / TARGET_FPMS;

        static MainLoop& getInstance();
        virtual ~MainLoop();
        
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

        const Window& getWindow() const;
        Window& getWindow();
    private:
        void initialize();
        void loopOnce(const std::chrono::duration<long, std::milli>& frame, 
                      const std::chrono::duration<long, std::milli>& game);

        MainLoop();
        MainLoop(const MainLoop&) = delete;
    
        bool running;

        std::array<
            BasicEvent,
            size_t(BasicEventType::COUNT)
        > events;

        Window window;
};
