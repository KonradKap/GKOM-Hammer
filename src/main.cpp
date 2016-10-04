#include <iostream>
#include <memory>

#include <SFML/System/Sleep.hpp>

#include "game_logic/MainLoop.h"
#include "game_logic/Loopable.h"
#include "game_logic/event/Event.h"

#include "view/WindowListener.h"
#include "view/View.h"
#include "view/BattleView.h"

#include "model/BattleModel.h"

#include "commons/Getter.h"

class KappaView : public View {
    void onDraw(const BasicEventArgs&) {}
};

class KappaLoopable : public LoopableAdapter {
    void onUpdate(const BasicEventArgs& args) {std::cout << "LUL: " << args.frame_time << std::endl; sf::sleep(sf::milliseconds(3));} 
};

class KappaListener : public WindowListenerAdapter {
    void onClosed() const {MainLoop::getInstance().stop();};
    void onKeyPressed(const sf::Event::KeyEvent& event) const { if (event.code == sf::Keyboard::Key::Escape or event.code == sf::Keyboard::Key::Return) onClosed();}
};

int main() {
    sf::Vector2i keepo(3, 4);

    std::cout << "X: " << get<Axis::X>::primary(keepo) << std::endl;

    BattleModel model;
    BattleView view(model, std::make_unique<KappaListener>());
    view.connect();

    std::cout << "FPS:" << MainLoop::TARGET_FPS << std::endl;
    std::cout << "FPMS:" << MainLoop::TARGET_FPMS << std::endl;
    std::cout << "SPF:" << MainLoop::FRAME_TIME_SEC << std::endl;
    std::cout << "MSPF:" << MainLoop::FRAME_TIME_MSEC << std::endl;

    MainLoop::getInstance().start();
}
