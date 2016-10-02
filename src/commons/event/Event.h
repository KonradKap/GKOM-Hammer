 /*
  * Event.h
  *
  * 2.09.2016 r.
  *
  * Memotosh
  *
  */

#pragma once

class BasicEventArgs;

struct Event{
    void connect(std::function<void (const BasicEventArgs&)> callback) {}; 
    void disconnect(std::function<void (const BasicEventArgs&)> callback) {}; 
    void signal(BasicEventArgs) {};
};
