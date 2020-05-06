#include "Headers\Game.h"

#include <ctime>
#include <cmath>
#include <fstream>

Game::Game(size_t _board_size) : board_size(_board_size) {
    main_game_board = new int[_board_size*_board_size];
    for (size_t i = 0; i < _board_size*_board_size; i++)
    {
        main_game_board[i] = 0;
    }
    random_values_count = _board_size/2;
    random_values = new int[std::min((int)random_values_count, 5)];
    for (size_t i = 1; i <= std::min((int)random_values_count, 5); i++)
    {
        random_values[i-1] = pow(2, i);
    }

    // TEST
    // main_game_board[0] = 4;
    // main_game_board[1] = 16;
    // main_game_board[2] = 2;
    // main_game_board[3] = 8;
    // main_game_board[4] = 2;
    // main_game_board[5] = 8;
    // main_game_board[6] = 4;
    // main_game_board[7] = 2;
    // main_game_board[8] = 8;
    // main_game_board[9] = 2;
    // main_game_board[10] = 2;
    // main_game_board[11] = 4;
    // main_game_board[12] = 4;
    // main_game_board[13] = 4;
    // main_game_board[14] = 4;

    CURRENTSCORE = 0;
    std::ifstream file("common.bin", std::ios::binary);
    file.read((char*)&HIGHSCORE, sizeof(int));
    file.close();
}
 
Game::~Game() {
    delete[] main_game_board;
    delete[] random_values;
}

bool Game::game_over() {
    for (size_t i = 0; i < board_size*board_size; i++)
    {
        if(main_game_board[i] == 0) {
            return false;
        }
    }
    std::cout << "Game over!" << std::endl;
    return true;
}

bool Game::win_condition() {
    if (CURRENTSCORE == 2048) {
        std::cout << "YOU WIN!" << std::endl;
        return true;
    }
    return false;
}

void Game::update_score() {
    for (size_t i = 0; i < board_size*board_size; i++)
    {
        if(main_game_board[i] > CURRENTSCORE) {
            CURRENTSCORE = main_game_board[i];
        }
    }
}

void Game::game_move(char KEY) {
    bool in = false;
    if(KEY == 'w') {

        for (size_t i = 0; i < board_size; i++)
        {
            for (size_t j = 0; j < board_size; j++)
            {
                in = false;
                for (size_t k = 1; k < board_size-j; k++)
                {
                    if(main_game_board[i+j*board_size] == 0) {
                        main_game_board[i+j*board_size] += main_game_board[i+(j+k)*board_size];
                        main_game_board[i+(j+k)*board_size] = 0;
                    } else if(main_game_board[i+j*board_size] == main_game_board[i+(j+k)*board_size] && !in) {
                        main_game_board[i+j*board_size] += main_game_board[i+(j+k)*board_size];
                        main_game_board[i+(j+k)*board_size] = 0;
                        in = true;
                    } else if(main_game_board[i+(j+k)*board_size] != 0) {
                        break;
                    }
                }
            } 
        }

    } else if(KEY == 'a') {

        for (size_t i = 0; i < board_size; i++)
        {
            for (size_t j = 0; j < board_size; j++)
            {
                in = false;
                for (size_t k = 1; k < board_size-j; k++)
                {
                    if(main_game_board[i*board_size+j] == 0) {
                        main_game_board[i*board_size+j] += main_game_board[j+(i*board_size)+k];
                        main_game_board[j+(i*board_size)+k] = 0;
                    } else if(main_game_board[i*board_size+j] == main_game_board[j+(i*board_size)+k] && !in) {
                        main_game_board[i*board_size+j] += main_game_board[j+(i*board_size)+k];
                        main_game_board[j+(i*board_size)+k] = 0;
                        in = true;
                    } else if(main_game_board[j+(i*board_size)+k] != 0) {
                        break;
                    }
                }
            } 
        }

    } else if(KEY == 's') {
        
        for (size_t i = 0; i < board_size; i++)
        {
            for (int j = board_size-1; j >= 0; j--)
            {
                in = false;
                for (size_t k = 1; k <= j; k++)
                {
                    if(main_game_board[i+j*board_size] == 0) {
                        main_game_board[i+j*board_size] += main_game_board[i+(j-k)*board_size];
                        main_game_board[i+(j-k)*board_size] = 0;
                    } else if(main_game_board[i+j*board_size] == main_game_board[i+(j-k)*board_size] && !in) {
                        main_game_board[i+j*board_size] += main_game_board[i+(j-k)*board_size];
                        main_game_board[i+(j-k)*board_size] = 0;
                        in = true;
                    } else if(main_game_board[i+(j-k)*board_size] != 0) {
                        break;
                    }
                }
            } 
        }

    } else if(KEY == 'd') {
        
        for (size_t i = 0; i < board_size; i++)
        {
            for (int j = board_size-1; j >= 0; j--)
            {
                in = false;
                for (size_t k = 1; k <= j; k++)
                {
                    if(main_game_board[i*board_size+j] == 0) {
                        main_game_board[i*board_size+j] += main_game_board[i*board_size+j-k];
                        main_game_board[i*board_size+j-k] = 0;
                    } else if(main_game_board[i*board_size+j] == main_game_board[i*board_size+j-k] && !in) {
                        main_game_board[i*board_size+j] += main_game_board[i*board_size+j-k];
                        main_game_board[i*board_size+j-k] = 0;
                        in = true;
                    } else if(main_game_board[i*board_size+j-k] != 0) {
                        break;
                    }
                }
            } 
        }
    }
}

void Game::game_board_print() {
    int padding = 1;
    std::cout << "CURRENT SCORE: " << CURRENTSCORE;
    std::cout << " HIGH SCORE: " << HIGHSCORE << std::endl;
    for (size_t i = 1; i <= board_size*board_size; i++)
    {
        std::cout << main_game_board[i-1];
        
        if(CURRENTSCORE >= 10000) {
            padding = 5;
        } else if(CURRENTSCORE >= 1000) {
            padding = 4;
        } else if(CURRENTSCORE >= 100) {
            padding = 3;
        } else if(CURRENTSCORE >= 10) {
            padding = 2;
        }
        
        for (size_t j = 0; j < padding; j++)
        {
            std::cout << " ";
        }
        
        if(i % 4 == 0) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

int Game::randomizer() {
    return rand() % 16;
}

void Game::NORMAL_MODE() {
    int random_position, random_value;
    char KEY;
    srand(time(NULL));
    while (!game_over() && !win_condition())
    {
        do
        {
            random_position = randomizer();
        } while (main_game_board[random_position] != 0);

        random_value = random_values[rand() % random_values_count];
        main_game_board[random_position] = random_value;

        update_score();
        game_board_print();
        std::cin >> KEY;
        game_move(KEY);

    }
}

void Game::INSANE_MODE() {
    int random_position, random_value;
    char KEY;
    srand(time(NULL));
    while (!game_over())
    {
        do
        {
            random_position = randomizer();
        } while (main_game_board[random_position] != 0);

        random_value = random_values[rand() % random_values_count];
        main_game_board[random_position] = random_value;

        update_score();
        game_board_print();
        std::cin >> KEY;
        game_move(KEY);
    }
}

void Game::Start(std::string MODE) {
    if(MODE == "INSANE") {
        INSANE_MODE();
    } else if(MODE == "NORMAL") {
        NORMAL_MODE();
    }
    if(CURRENTSCORE > HIGHSCORE) {
        std::cout << "NEW HIGHSCORE: " << CURRENTSCORE << std::endl;
        HIGHSCORE = CURRENTSCORE;
        std::ofstream file("common.bin", std::ios::binary);
        file.write((char*)&HIGHSCORE, sizeof(int));
        file.close();
    }
}