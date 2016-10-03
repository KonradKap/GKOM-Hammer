#include <iostream>
#include <memory>

#include "game_logic/MainLoop.h"
#include "game_logic/Loopable.h"
#include "game_logic/event/Event.h"

#include "view/WindowListener.h"
#include "view/View.h"

#include "GameConstants.h"

class KappaView : public View {
    void onDraw(const BasicEventArgs&) {}
};

class KappaLoopable : public LoopableAdapter {
    void onUpdate(const BasicEventArgs& args) {std::cout << "LUL: " << args.frame_time << std::endl;}
};

int main() {
    KappaView view;
    view.setWindowListener(std::make_unique<WindowListenerAdapter>());
    view.connect();
    KappaLoopable kappa;
    kappa.connect();

    std::cout << "FPS:" << TARGET_FPS << std::endl;
    std::cout << "FPMS:" << TARGET_FPMS << std::endl;
    std::cout << "SPF:" << FRAME_TIME_SEC << std::endl;
    std::cout << "MSPF:" << FRAME_TIME_MSEC << std::endl;

    MainLoop::getInstance().start();
}
