#include <iostream>
#include <memory>

#include <SFML/System/Sleep.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include "game_logic/MainLoop.h"
#include "game_logic/Loopable.h"
#include "game_logic/event/Event.h"

#include "view/WindowListener.h"
#include "view/View.h"
#include "view/BattleView.h"

#include "model/BattleModel.h"
#include "model/unit/Unit.h"

#include "commons/Getter.h"
#include "commons/Vector.h"
#include "commons/Utility.h"
#include "commons/ShapeUtils.h"

#include "collisions/SAT.h"

class KappaListener : public WindowListenerAdapter {
    void onClosed() const {MainLoop::getInstance().stop();};
    void onKeyPressed(const sf::Event::KeyEvent& event) const {
        switch(event.code) {
            case sf::Keyboard::Key::Escape:
            case sf::Keyboard::Key::Return:
                onClosed();
            default:
                return;
        }
    }
};

class KappaUnit : public Unit {
    public:
        KappaUnit(const sf::ConvexShape& s) : Unit(s) {}
    private:
        virtual void onUpdate(const BasicEventArgs& args) {
        }
};

namespace sf {
    typedef Vector2<double> Vector2d;
}

int main() {
    sf::ConvexShape polygon = create_shape(4, 50);
    polygon.setOutlineColor(sf::Color::Red);
    polygon.setFillColor(sf::Color::Transparent);
    polygon.setOutlineThickness(5);
    polygon.setPosition(10, 20);

    sf::ConvexShape kappaShape = create_shape(6, 40);
    kappaShape.setOutlineColor(sf::Color::Red);
    kappaShape.setFillColor(sf::Color::Transparent);
    kappaShape.setOutlineThickness(5);
    kappaShape.setPosition(200, 200);

    BattleModel model;
    model.addUnit(std::unique_ptr<Unit>{new Unit(polygon)});
    model.addUnit(std::unique_ptr<Unit>{new KappaUnit(kappaShape)});

    kappaShape.setPosition(400,400);
    model.addUnit(std::unique_ptr<Unit>{new KappaUnit(kappaShape)});

    model.connect();
    BattleView view(model);
    view.setWindowListener(std::make_unique<KappaListener>());
    view.connect();
    MainLoop::getInstance().start();
}
