#include <iostream>

#include "commons/MainLoop.h"
#include "commons/Loopable.h"

int main() {
    LoopableAdaptor temp;
    temp.start();
    MainLoop::getInstance().start();   
}

