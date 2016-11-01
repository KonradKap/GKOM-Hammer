 /*
  * BattleModel.h
  *
  * 4.09.2016 r.
  *
  * Memotosh
  *
  */

#pragma once

#include <array>
#include <vector>
#include <memory>

#include "Model.h"

class Unit;
template<class T>
class Vector;

class BattleModel : public Model {
    public:
        virtual ~BattleModel();

        const std::vector<std::unique_ptr<Unit>>& getUnits() const;

        void addUnit(std::unique_ptr<Unit> u);
    private:
        typedef std::vector<Unit*> chunk_t;
        typedef std::array< std::array < chunk_t, CHUNK_Y >, CHUNK_X > board_t;

        void onUpdate(const BasicEventArgs& args);

        void updateChunks();
        chunk_t* determineChunk(const Vector<double>& point);
        void clearChunks();

        void detectCollisions();
        void resolveCollisions(Unit* lhs, Unit* rhs, const Vector<double>& overlap);

        board_t board;
        std::vector<std::unique_ptr<Unit>> units;
};
