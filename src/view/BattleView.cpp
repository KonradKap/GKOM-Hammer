#include "BattleView.h"

#include <boost/range/irange.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Vertex.hpp>

#include "WindowListener.h"
#include "model/BattleModel.h"
#include "model/unit/Unit.h"
#include "commons/Getter.h"

BattleView::BattleView(
    const BattleModel& source,
    std::unique_ptr<WindowListener> listener) :
        View(std::move(listener)),
        source(source) {
}

void BattleView::onDraw(const BasicEventArgs&) {
    window.clear(sf::Color::White);
    drawGrid();
    drawUnits();
    window.display();
}

template <Axis AXIS>
    void BattleView::drawGridIn() {
        for (auto i : boost::irange(0, get<AXIS>::secondary(Model::CHUNK))) {
            sf::Vector2f pos_begin = 
                create<AXIS>::template primary<sf::Vector2, float>(0, i*Model::CHUNK_SIZE);
            sf::Vector2f pos_end = 
                create<AXIS>::template primary<sf::Vector2, float>(
                    get<AXIS>::primary(BattleView::WINDOW), 
                    i*Model::CHUNK_SIZE);
            sf::Vertex line[] = {
                sf::Vertex(pos_begin, sf::Color::Green),
                sf::Vertex(pos_end, sf::Color::Green)};
            window.draw(line, 2, sf::Lines);
        }
    }

void BattleView::drawGrid() {
    forEach(drawGridIn);
}

void BattleView::drawUnits() {
    for(const auto& unit : source.getUnits()) {
        window.draw(unit->getShape());
    }
}


