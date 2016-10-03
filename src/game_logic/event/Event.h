 /*
  * Event.h
  *
  * 2.09.2016 r.
  *
  * Memotosh
  *
  */

#pragma once

#include <vector>
#include <functional>

template<class Receiver, class... Args>
    class Event {
        public:
            typedef void (Receiver::*callback_function)(Args...);

            inline void connect(Receiver* receiver, callback_function call);
            inline void disconnect(Receiver* receiver, callback_function call);
            inline void signal(Args...);
        private:
            typedef std::pair<callback_function, Receiver*> callback_pair;

            std::vector< callback_pair > callbacks;
    };

template<class Receiver>
    class Event<Receiver, void> {
        public:
            typedef void (Receiver::*callback_function)(void);

            inline void connect(Receiver*, callback_function callback);
            inline void disconnect(Receiver*, callback_function callback);
            inline void signal();
        private:
            typedef std::pair<callback_function, Receiver*> callback_pair;

            std::vector< callback_pair > callbacks;
    };

#include "Event.hpp"
