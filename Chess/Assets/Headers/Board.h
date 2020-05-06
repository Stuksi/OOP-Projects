#ifndef BOARD_H
#define BOARD_H

#include "Tile.h"

class Board {
private:
    Tile* board[8][8];
public:
    Board();

    void print_board();
};

#endif