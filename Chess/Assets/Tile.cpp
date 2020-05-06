#include "Headers\Tile.h"

Tile::Tile(size_t _pos_x, size_t _pos_y, Piece* _piece) : pos_x(_pos_x), pos_y(_pos_y), piece(_piece) {} 

void Tile::print_tile() {
    if(piece != nullptr) {
        piece->print_piece();
        return;
    }
    std::cout << "#";
}