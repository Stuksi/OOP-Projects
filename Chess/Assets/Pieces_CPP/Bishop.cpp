#include "..\Headers\Pieces_H\Bishop.h"

Bishop::Bishop(size_t _pos_x, size_t _pos_y, size_t _side) : Piece(_pos_x, _pos_y, _side) {}

bool Bishop::can_move (size_t move_x, size_t move_y, Piece* board[8][8]) {
    if(move_x != pos_x && move_y != pos_y && std::abs((int)(move_x-pos_x)) == std::abs((int)(move_y-pos_y))) {
        size_t j = pos_y, i = pos_x;
        while (j != move_y)
        {
            if(board[j][i] != nullptr) {
                return false;
            }
            if(j < move_y) {
                j++;
            } else {
                j--;
            }
            if(i < move_x) {
                i++;
            } else {
                i--;
            }
        }
        return true; 
    }
    return false;
}

void Bishop::print_piece() {
    if(side == 0) {
        std::cout << 'B';
    } else {
        std::cout << 'b';
    }
}