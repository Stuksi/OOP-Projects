#ifndef QUEEN_H
#define QUEEN_H

#include "..\Piece.h"

class Queen : public Piece {
public:
    Queen (size_t _pos_x, size_t _pos_y, size_t _side);

    bool can_move(size_t move_x, size_t move_y, Piece* board[8][8]);
    void print_piece();
};

#endif