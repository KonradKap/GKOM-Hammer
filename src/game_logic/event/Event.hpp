#pragma once

#include <algorithm>

template<class Receiver, class... Args>
    void Event<Receiver, Args...>::connect(
            Receiver* receiver,
            typename Event<Receiver, Args...>::callback_function callback) {

        auto pair = std::make_pair(callback, receiver);
        if(std::find(std::begin(callbacks), std::end(callbacks), pair) == std::end(callbacks))
            callbacks.push_back(pair);
    }

template<class Receiver, class... Args>
    void Event<Receiver, Args...>::disconnect(
            Receiver* receiver,
            typename Event<Receiver, Args...>::callback_function callback) {

        callbacks.erase( 
            std::remove(
                std::begin(callbacks),
                std::end(callbacks),
                std::make_pair(callback, receiver)),
            std::end(callbacks));
    }

template<class Receiver, class... Args>
    void Event<Receiver, Args...>::signal(Args... args) {
        for (auto pair : callbacks) {
            auto callback = std::bind(pair.first, pair.second, args...);
            callback(args...);
        }
    }

template<class Receiver>
    void Event<Receiver, void>::connect(
            Receiver* receiver,
            Event<Receiver, void>::callback_function callback) {

        auto pair = std::make_pair(callback, receiver);
        if(std::find(std::begin(callbacks), std::end(callbacks), pair) == std::end(callbacks))
            callbacks.insert(pair);
    }

template<class Receiver>
    void Event<Receiver, void>::disconnect(
            Receiver* receiver,
            Event<Receiver, void>::callback_function callback) {

        callbacks.erase( 
            std::remove(
                std::begin(callbacks),
                std::end(callbacks),
                std::make_pair(callback, receiver)),
            std::end(callbacks));
    }

template<class Receiver>
    void Event<Receiver, void>::signal() {
        for (auto pair : callbacks){
            auto callback = std::bind(pair.first, pair.second);
            callback();
        }
    }
