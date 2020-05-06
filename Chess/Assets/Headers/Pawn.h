#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(size_t pos_x, size_t pos_y, size_t side);

    void move(size_t move_x, size_t move_y);
    void print_piece();
};

#endif