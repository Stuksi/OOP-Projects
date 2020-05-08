#include "Headers\Piece.h"

Piece::Piece(size_t _pos_x, size_t _pos_y, size_t _side) : pos_x(_pos_x), pos_y(_pos_y), side(_side) {}

size_t Piece::get_side() {
    return side;
}