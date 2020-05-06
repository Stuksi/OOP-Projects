#ifndef PIECE_H
#define PIECE_H

#include <iostream>

class Piece {
private:
    size_t pos_x, pos_y;
protected:
    size_t side;
public:
    Piece (size_t _pos_x, size_t _pos_y, size_t _side);

    virtual void move(size_t move_x, size_t move_y) = 0;
    virtual void print_piece() = 0;
};

#endif