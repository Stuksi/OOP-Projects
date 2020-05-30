#include "2048.h"

#include <iostream>
#include <ctime>

Game_2048::Game_2048() {
    score = 0;
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            player_board[i][j] = 0;
        }
    }
    copy_player_board[0][0] = 1;
}

bool Game_2048::game_over() {
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            if(player_board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

void Game_2048::print_board() {
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            std::cout << player_board[i][j] << " ";
        }
        std::cout << std::endl;
    }    
    std::cout << std::endl;
}

void Game_2048::move_up() {
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            for (size_t k = j+1; k < 4; k++)
            {
                if(player_board[j][i] != player_board[k][i] && player_board[j][i] != 0 && player_board[k][i] != 0) {
                    break;
                }
                if(player_board[j][i] == 0 && player_board[k][i] != 0){
                    player_board[j][i] = player_board[k][i];
                    player_board[k][i] = 0;
                }else if(player_board[j][i] == player_board[k][i] && player_board[j][i] != 0) {
                    player_board[j][i] *= 2;
                    player_board[k][i] = 0;
                    score += player_board[j][i];
                    break;
                }
            }
        }
    }
}

void Game_2048::move_left() {
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            for (size_t k = j+1; k < 4; k++)
            {
                if(player_board[i][j] != player_board[i][k] && player_board[i][j] != 0 && player_board[i][k] != 0) {
                    break;
                }
                if(player_board[i][j] == 0 && player_board[i][k] != 0){
                    player_board[i][j] = player_board[i][k];
                    player_board[i][k] = 0;
                }else if(player_board[i][j] == player_board[i][k] && player_board[i][j] != 0) {
                    player_board[i][j] *= 2;
                    player_board[i][k] = 0;
                    score += player_board[i][j];
                    break;
                }
            }
        }
    }
}

void Game_2048::move_down() {
    for (size_t i = 0; i < 4; i++)
    {
        for (int j = 3; j >= 1; j--)
        {
            for (int k = j-1; k >= 0; k--)
            {
                if(player_board[j][i] != player_board[k][i] && player_board[j][i] != 0 && player_board[k][i] != 0) {
                    break;
                }
                if(player_board[j][i] == 0 && player_board[k][i] != 0){
                    player_board[j][i] = player_board[k][i];
                    player_board[k][i] = 0;
                }else if(player_board[j][i] == player_board[k][i] && player_board[j][i] != 0) {
                    player_board[j][i] *= 2;
                    player_board[k][i] = 0;
                    score += player_board[j][i];
                    break;
                }
            }
        }
    }
}

void Game_2048::move_right() {
    for (size_t i = 0; i < 4; i++)
    {
        for (int j = 3; j >= 1; j--)
        {
            for (int k = j-1; k >= 0; k--)
            {
                if(player_board[i][j] != player_board[i][k] && player_board[i][j] != 0 && player_board[i][k] != 0) {
                    break;
                }
                if(player_board[i][j] == 0 && player_board[i][k] != 0){
                    player_board[i][j] = player_board[i][k];
                    player_board[i][k] = 0;
                }else if(player_board[i][j] == player_board[i][k] && player_board[i][j] != 0) {
                    player_board[i][j] *= 2;
                    player_board[i][k] = 0;
                    score += player_board[i][j];
                    break;
                }
            }
        }
    }
}

void Game_2048::copy_board() {
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            copy_player_board[i][j] = player_board[i][j];
        }
    }
}

bool Game_2048::copy_move() {
    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            if(copy_player_board[i][j] != player_board[i][j]) {
                return true;
            }
        }
    }
    return false;
}

void Game_2048::Start() {
    char KEY;
    int values[2] = {2, 4}, row, col;
    srand(time(NULL));
    do
    {
        std::cout << "Score: " << score << std::endl;
        if(copy_move()) {
            do
            {
                row = rand() % 4;
                col = rand() % 4;
            } while (player_board[row][col] != 0);
            player_board[row][col] = values[rand()%2];    
        }
        print_board();
        copy_board();
        std::cin >> KEY;
        if(KEY == 'w') {
            move_up();
        } else if(KEY == 'a') {
            move_left();
        } else if(KEY == 's') {
            move_down();
        } else if(KEY == 'd') {
            move_right();
        }
    } while (!game_over());
    std::cout << "Game Over!" << std::endl;
}
