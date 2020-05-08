#include "..\Headers\Pieces_H\Knight.h"

Knight::Knight(size_t _pos_x, size_t _pos_y, size_t _side) : Piece(_pos_x, _pos_y, _side) {}

bool Knight::can_move (size_t move_x, size_t move_y, Piece* board[8][8]) {
    return move_x == pos_x + 1 && move_y == pos_y + 2
        || move_x == pos_x + 2 && move_y == pos_y + 1
        || move_x == pos_x + 1 && move_y == pos_y - 2
        || move_x == pos_x + 2 && move_y == pos_y - 1
        || move_x == pos_x - 1 && move_y == pos_y + 2
        || move_x == pos_x - 2 && move_y == pos_y + 1
        || move_x == pos_x - 1 && move_y == pos_y - 2
        || move_x == pos_x - 2 && move_y == pos_y - 1; 
}

void Knight::print_piece() {
    if(side == 0) {
        std::cout << 'K';
    } else {
        std::cout << 'k';
    }
}