 /*
  * Loopable.h
  * 
  * 2.09.2016 r.
  *
  * Memotosh
  */

#pragma once

class MainLoop;
class EventArgs;

class Loopable {
    friend MainLoop;

    public:
        Loopable();
        virtual ~Loopable();

        void pause();
        void resume();
        void start();
        void stop();
    private:
        virtual void onStart (EventArgs&) = 0;
        virtual void onUpdate(EventArgs&) = 0;
        virtual void onPause (EventArgs&) = 0;
        virtual void onResume(EventArgs&) = 0;
        virtual void onStop  (EventArgs&) = 0;
};

class LoopableAdapter : public Loopable {
    virtual void onStart (EventArgs&) {} 
    virtual void onUpdate(EventArgs&) {}
    virtual void onResume(EventArgs&) {}
    virtual void onPause (EventArgs&) {} 
    virtual void onStop  (EventArgs&) {} 

    virtual ~LoopableAdapter() {}
};
