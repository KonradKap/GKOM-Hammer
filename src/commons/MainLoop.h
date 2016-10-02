 /*
  * MainLoop,h
  *
  * 2.09.2016 r.
  *
  * Memotosh
  */

#pragma once

#include <memory>
#include <set>

class Loopable;

class MainLoop {
    public:
        static MainLoop& getInstance();



        void start();
        void pause();
        void resume();
        void exit();
    private:
        void loopOnce();

        MainLoop();
        MainLoop(const MainLoop&) = delete;

        struct LoopableManager {
            typedef std::set<std::shared_ptr<Loopable> > Container;
            void moveLoopable(
                    Container& from, 
                    Container& to, 
                    std::shared_ptr<Loopable> loopable);
            void insertLoopable(
                    Container& to, 
                    std::shared_ptr<Loopable> loopable);
            void deleteLoopable(
                    Container& to, 
                    std::shared_ptr<Loopable> loopable);
            
            Container active_loopables;
            Container paused_loopables;
        };

        LoopableManager manager;
};
