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
        View();
        View(const View& view) = delete;
        virtual ~View();

        void setWindowListener(std::unique_ptr<WindowListener> new_listener);

    private:
        virtual void onDraw(const BasicEventArgs& args) = 0;
        void onUpdate(const BasicEventArgs& args);

        sf::RenderWindow window;
        std::unique_ptr<WindowListener> window_listener;
};
