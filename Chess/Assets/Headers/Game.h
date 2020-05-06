#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Piece.h"
#include "Tile.h"

class Game {
private:
    void skipEmptySpaces(std::string& string, size_t &k);
    bool game_over();
public:
    void Start();
};

#endif