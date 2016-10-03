#include <iostream>

#include "commons/MainLoop.h"
#include "commons/Loopable.h"
#include "commons/event/Event.h"

#include "GameConstants.h"

class TestLoopable : public LoopableAdapter {
    public:
    void onStart (const BasicEventArgs& args) {std::cout << "str" << a << std::endl;}
    void onUpdate(const BasicEventArgs& args) {std::cout << "upd" << a << std::endl;}

    int a = 4;
};

int main() {

    std::cout << "FPS:" << TARGET_FPS << std::endl;
    std::cout << "FPMS:" << TARGET_FPMS << std::endl;
    std::cout << "SPF:" << FRAME_TIME_SEC << std::endl;
    std::cout << "MSPF:" << FRAME_TIME_MSEC << std::endl;
}
