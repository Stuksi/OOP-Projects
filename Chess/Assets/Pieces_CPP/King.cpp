#include "..\Headers\Pieces_H\King.h"

King::King(size_t _pos_x, size_t _pos_y, size_t _side) : Piece(_pos_x, _pos_y, _side) {}

bool King::can_move (size_t move_x, size_t move_y, Piece* board[8][8]) {
    if(move_x != pos_x || move_y != pos_y) {
        return std::abs((int)(move_x-pos_x)) <= 1
            && std::abs((int)(move_y-pos_y)) <= 1;
    }
    return false;
}

void King::print_piece() {
    if(side == 0) {
        std::cout << 'Z';
    } else {
        std::cout << 'z';
    }
}