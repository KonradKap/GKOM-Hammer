#include "MainLoop.h"

#include <thread>
#include <chrono>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/gl.h> 

#include "model/Shape.h"
#include "game_logic/exceptions/OpenGlException.h"
#include "GameConstants.h"

const decltype(MainLoop::TARGET_FPS) MainLoop::TARGET_FPS;
const decltype(MainLoop::TARGET_FPMS) MainLoop::TARGET_FPMS;
const decltype(MainLoop::FRAME_TIME_SEC) MainLoop::FRAME_TIME_SEC;
const decltype(MainLoop::FRAME_TIME_MSEC) MainLoop::FRAME_TIME_MSEC;
const Vector2I MainLoop::WINDOW{WINDOW_X, WINDOW_Y};

MainLoop& MainLoop::getInstance() {
    static MainLoop instance;
    return instance;
}

MainLoop::MainLoop() : 
        running(false) {

            initialize();
}

MainLoop::~MainLoop() {
    glfwTerminate();
}

void MainLoop::connect(
        BasicEventType type, 
        Loopable* caller,
        BasicEvent::callback_function callback) {

    events[size_t(type)].connect(caller, callback);
}

void MainLoop::disconnect(
        BasicEventType type, 
        Loopable* caller,
        BasicEvent::callback_function callback) {

    events[size_t(type)].disconnect(caller, callback);
}

void MainLoop::start() {
    using namespace std::chrono;
    running = true;

    events[size_t(BasicEventType::START)].signal({});

    const auto start = time_point_cast<milliseconds>(system_clock::now());
    auto frame = time_point_cast<milliseconds>(system_clock::now());
    while( running ) {
        loopOnce(time_point_cast<milliseconds>(system_clock::now()) - frame,
                 time_point_cast<milliseconds>(system_clock::now()) - start);
        frame = time_point_cast<milliseconds>(system_clock::now());
    }

    events[size_t(BasicEventType::STOP)].signal({
            time_point_cast<milliseconds>(system_clock::now()) - start});
}

void MainLoop::initialize() {
    if (glfwInit() != GL_TRUE) 
        throw OpenGlException("glfwInit failed");

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    window = Window(WINDOW_X, WINDOW_Y, GAME_TITLE);

    glfwMakeContextCurrent(window.get());

    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK)
        throw OpenGlException("glewInit failed");

    glViewport(0, 0, WINDOW_X, WINDOW_Y);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glDisable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}

void MainLoop::stop() {
    running = false;
}

void MainLoop::loopOnce(const std::chrono::duration<long, std::milli>& frame, 
        const std::chrono::duration<long, std::milli>& game) {

    glfwPollEvents();
    events[size_t(BasicEventType::UPDATE)].signal({frame});
    events[size_t(BasicEventType::DRAW)].signal({game});

    std::this_thread::sleep_for(FRAME_TIME_MSEC - frame);
}

const Window& MainLoop::getWindow() const {
    return window;
}

Window& MainLoop::getWindow() {
    return const_cast<Window&>(static_cast<const MainLoop*>(this)->getWindow());
}
