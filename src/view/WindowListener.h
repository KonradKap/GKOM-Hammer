 /*
  * WindowListner.h
  *
  * 3.09.2016 r.
  *
  * Memotosh
  *
  */

#pragma once

#include <SFML/Window/Event.hpp>

class WindowListener {
    public:
        virtual ~WindowListener();
        
        void readSingleEvent(const sf::Event& event) const;

    private:
        virtual void onClosed() const = 0;
        virtual void onLostFocus() const = 0;
        virtual void onGainedFocus() const = 0;
        virtual void onKeyPressed(const sf::Event::KeyEvent& event) const = 0;
        virtual void onKeyReleased(const sf::Event::KeyEvent& event) const = 0;
        virtual void onMouseWheelMoved(const sf::Event::MouseWheelEvent& event) const = 0;
        virtual void onMouseButtonPressed(const sf::Event::MouseButtonEvent& event) const = 0;
        virtual void onMouseButtonReleased(const sf::Event::MouseButtonEvent& event) const = 0;
        virtual void onMouseMoved(const sf::Event::MouseMoveEvent& event) const = 0;
        virtual void onMouseEntered() const = 0;
        virtual void onMouseLeft() const = 0;
};

class WindowListenerAdapter : public WindowListener {
    public:
        virtual ~WindowListenerAdapter() {}
    private:
        virtual void onClosed() const {}
        virtual void onLostFocus() const {}
        virtual void onGainedFocus() const {}
        virtual void onKeyPressed(const sf::Event::KeyEvent& event) const {}
        virtual void onKeyReleased(const sf::Event::KeyEvent& event) const {}
        virtual void onMouseWheelMoved(const sf::Event::MouseWheelEvent& event) const {}
        virtual void onMouseButtonPressed(const sf::Event::MouseButtonEvent& event) const {}
        virtual void onMouseButtonReleased(const sf::Event::MouseButtonEvent& event) const {}
        virtual void onMouseMoved(const sf::Event::MouseMoveEvent& event) const {}
        virtual void onMouseEntered() const {}
        virtual void onMouseLeft() const {}
};

