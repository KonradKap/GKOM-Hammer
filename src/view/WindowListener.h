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

namespace sf {
    class RenderWindow;
} //namespace sf

class WindowListener {
       friend class View;
    public:
        WindowListener() = default;
        WindowListener(const WindowListener& other) = delete;
        virtual ~WindowListener();
        
        void readSingleEvent(sf::Event event) const;

    private:
        virtual void onClosed() const = 0;
        virtual void onLostFocus() const = 0;
        virtual void onGainedFocus() const = 0;
        virtual void onKeyPressed(sf::Event::KeyEvent event) const = 0;
        virtual void onKeyReleased(sf::Event::KeyEvent event) const = 0;
        virtual void onMouseWheelMoved(sf::Event::MouseWheelEvent event) const = 0;
        virtual void onMouseButtonPressed(sf::Event::MouseButtonEvent event) const = 0;
        virtual void onMouseButtonReleased(sf::Event::MouseButtonEvent event) const = 0;
        virtual void onMouseMoved(sf::Event::MouseMoveEvent event) const = 0;
        virtual void onMouseEntered() const = 0;
        virtual void onMouseLeft() const = 0;

        void setWindow(sf::RenderWindow* source);
        sf::RenderWindow* source;
};

class WindowListenerAdapter : public WindowListener {
    public:
        virtual ~WindowListenerAdapter() {}
    private:
        virtual void onClosed() const {}
        virtual void onLostFocus() const {}
        virtual void onGainedFocus() const {}
        virtual void onKeyPressed(sf::Event::KeyEvent event) const {}
        virtual void onKeyReleased(sf::Event::KeyEvent event) const {}
        virtual void onMouseWheelMoved(sf::Event::MouseWheelEvent event) const {}
        virtual void onMouseButtonPressed(sf::Event::MouseButtonEvent event) const {}
        virtual void onMouseButtonReleased(sf::Event::MouseButtonEvent event) const {}
        virtual void onMouseMoved(sf::Event::MouseMoveEvent event) const {}
        virtual void onMouseEntered() const {}
        virtual void onMouseLeft() const {}
};
