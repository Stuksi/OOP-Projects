#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include <iostream>

class Board {
private:
    Piece* board[8][8];
public:
    Board();
    ~Board();

    void print_board();
    void move_piece(size_t current_x, size_t current_y, size_t move_x, size_t move_y);
};

#endif