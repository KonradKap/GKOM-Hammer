 /*
  * Model.h
  *
  * 4.09.2016 r.
  *
  * Memotosh
  */

#pragma once

#include <SFML/System/Vector2.hpp>

#include "../game_logic/Loopable.h"

class Model : public LoopableAdapter {
    public:
        constexpr static const int BOARD_X = 800;
        constexpr static const int BOARD_Y = 640;
        static const sf::Vector2i BOARD;

        constexpr static const int CHUNK_SIZE = 80;

        constexpr static const int CHUNK_X = BOARD_X / CHUNK_SIZE;
        constexpr static const int CHUNK_Y = BOARD_Y / CHUNK_SIZE;
        static const sf::Vector2i CHUNK;
        
        static_assert(BOARD_X == CHUNK_SIZE*CHUNK_X, "Board size is not divisible by chunk size");
        static_assert(BOARD_Y == CHUNK_SIZE*CHUNK_Y, "Board size is not divisible by chunk size");

        virtual ~Model() {}
};
