#include "BattleView.h"

#include <boost/range/irange.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Vertex.hpp>

#include "WindowListener.h"
#include "../model/BattleModel.h"
#include "../commons/Getter.h"

BattleView::BattleView(
    const BattleModel& source,
    std::unique_ptr<WindowListener> listener) :
        View(std::move(listener)),
        source(source) {
}

void BattleView::onDraw(const BasicEventArgs&) {
    window.clear(sf::Color::White);
    drawGrid();
    window.display();
}

template <Axis AXIS>
    void BattleView::drawGridIn() {
        for (auto i : boost::irange(0, get<AXIS>::const_secondary(Model::CHUNK))) {
            sf::Vector2f pos_begin;
            get<AXIS>::secondary(pos_begin) = i*Model::CHUNK_SIZE;
            sf::Vector2f pos_end;
            get<AXIS>::primary(pos_end) = get<AXIS>::const_primary(BattleView::WINDOW);
            get<AXIS>::secondary(pos_end) = i*Model::CHUNK_SIZE;

            sf::Vertex line[] = {
                sf::Vertex(pos_begin, sf::Color::Green),
                sf::Vertex(pos_end, sf::Color::Green)};
            window.draw(line, 2, sf::Lines);
        }
    }

void BattleView::drawGrid() {
    drawGridIn<Axis::X>();
    drawGridIn<Axis::Y>();
}

