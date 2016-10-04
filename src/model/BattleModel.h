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

#include "Model.h"

class BattleModel : public Model {
    public:
        virtual ~BattleModel();
    private:
        typedef std::vector<int> chunk_t;
        typedef std::array< std::array < chunk_t, CHUNK_Y >, CHUNK_X > board_t;

        void onUpdate(const BasicEventArgs& args);

        board_t board;
};
