#ifndef TILE_H
#define TILE_H

#include "Piece.h"

class Tile {
private:
    size_t pos_x, pos_y;
    Piece* piece;
public:
    Tile (size_t _pos_x, size_t _pos_y, Piece* _piece);

    void print_tile();
};

#endif