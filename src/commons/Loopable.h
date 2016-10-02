 /*
  * Loopable.h
  * 
  * 2.09.2016 r.
  *
  * Memotosh
  */

#pragma once

class BasicEventArgs;

class Loopable {
    public:
        virtual ~Loopable();

        virtual void connect();
        virtual void disconnect();
    private:
        virtual void onStart (const BasicEventArgs&) = 0;
        virtual void onPause (const BasicEventArgs&) = 0;
        virtual void onResume(const BasicEventArgs&) = 0;
        virtual void onStop  (const BasicEventArgs&) = 0;
        virtual void onUpdate(const BasicEventArgs&) = 0;
};

class LoopableAdapter : public Loopable {
    public:
        LoopableAdapter();
        virtual ~LoopableAdapter();
    private:
        virtual void onStart (const BasicEventArgs&) {} 
        virtual void onUpdate(const BasicEventArgs&) {}
        virtual void onResume(const BasicEventArgs&) {}
        virtual void onPause (const BasicEventArgs&) {} 
        virtual void onStop  (const BasicEventArgs&) {} 
};
