#ifndef PIECE_H
#define PIECE_H

#include <iostream>

class Piece {
protected:
    size_t pos_x, pos_y, side;
public:
    Piece (size_t _pos_x, size_t _pos_y, size_t _side);
    size_t get_side();

    virtual bool can_move(size_t move_x, size_t move_y, Piece* board[8][8]) = 0;
    virtual void print_piece() = 0;
};

#endif