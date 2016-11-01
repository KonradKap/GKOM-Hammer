#include "BattleModel.h"

#include <iostream>

#include "model/unit/Unit.h"
#include "collisions/SAT.h"
#include "commons/ShapeUtils.h"
#include "commons/Vector.h"
#include "commons/Utility.h"

//temporary
#include "view/View.h"
#include "game_logic/MainLoop.h"

BattleModel::~BattleModel() {
}

const std::vector<std::unique_ptr<Unit>>& BattleModel::getUnits() const {
    return units;
}

void BattleModel::addUnit(std::unique_ptr<Unit> u) {
    units.push_back(std::move(u));
    units.back()->connect();
}

void BattleModel::onUpdate(const BasicEventArgs& args) {
    updateChunks();
    detectCollisions();
}

void BattleModel::updateChunks() {
    clearChunks();
    for (auto& unit : units) {
        for (const auto& vertex : get_vertices(unit->getShape())) {
            auto chunk = determineChunk(vertex);
            if(chunk != nullptr) {
                chunk->erase(std::remove(
                        std::begin(*chunk),
                        std::end(*chunk),
                        unit.get()), 
                    std::end(*chunk));
                chunk->push_back(unit.get());
            }
        }
    }
}

void BattleModel::clearChunks() {
    for (auto& col : board) 
        for (auto& chunk : col) {
            chunk.clear();
        }
}

BattleModel::chunk_t* BattleModel::determineChunk(const VectorD& point) {
    const VectorI index = VectorI(point/CHUNK_SIZE);
    if(index.x < 0 or index.x >= CHUNK_X or index.y < 0 or index.y >= CHUNK_Y)
        return nullptr;

    return &board[index.x][index.y];
}

void BattleModel::detectCollisions() {
    for (auto& col : board)
    for (auto& chunk : col)
    for (unsigned i = 0; i < chunk.size(); ++i)
    for (unsigned j = i+1; j < chunk.size(); ++j) {
        const auto result = collision_check(chunk[i]->getShape(), chunk[j]->getShape());
        if(result.first == true) 
            resolveCollisions(chunk[i], chunk[j], result.second);
    }
}

void BattleModel::resolveCollisions(Unit* lhs, Unit* rhs, const VectorD& overlap) {
    if (VectorD(rhs->getShape().getPosition()-lhs->getShape().getPosition()).dot_product(overlap) > 0) {
        lhs->getShape().move(-sf::Vector2f(overlap/2));
        rhs->getShape().move(sf::Vector2f(overlap/2));
    } else {
        lhs->getShape().move(sf::Vector2f(overlap/2));
        rhs->getShape().move(-sf::Vector2f(overlap/2));
    }
}
