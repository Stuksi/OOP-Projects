#include "Headers\Pawn.h"

Pawn::Pawn(size_t pos_x, size_t pos_y, size_t side) : Piece(pos_x, pos_y, side) {}

void Pawn::move (size_t move_x, size_t move_y) {

}

void Pawn::print_piece() {
    if(side == 0) {
        std::cout << 'P';
    } else {
        std::cout << 'p';
    }
}