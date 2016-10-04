 /*
  * View.h
  *
  * 3.09.2016 r.
  *
  * Memotosh
  *
  */

#pragma once

#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>

#include "../game_logic/Loopable.h"

class WindowListener;
class BasicEventArgs;

class View : public LoopableAdapter {
    public:
        constexpr static const int WINDOW_X = 800;
        constexpr static const int WINDOW_Y = 640;
        static const sf::Vector2i WINDOW;

        View();
        View(const View& view) = delete;
        View(std::unique_ptr<WindowListener> listener);
        virtual ~View();

        void setWindowListener(std::unique_ptr<WindowListener> new_listener);
    protected:
        sf::RenderWindow window;
    private:
        virtual void onDraw(const BasicEventArgs& args) = 0;
        virtual void onUpdate(const BasicEventArgs& args);

        std::unique_ptr<WindowListener> window_listener;
};
