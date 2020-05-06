#ifndef GAME_H
#define GAME_H

#include <string>
#include <iostream>

class Game {
private:
    int* main_game_board;
    int* random_values;
    size_t board_size, random_values_count;
    int HIGHSCORE, CURRENTSCORE;

    int randomizer();

    bool win_condition();
    bool game_over();

    void game_move(char KEY);
    void game_board_print();
    void update_score();

    void INSANE_MODE();
    void NORMAL_MODE();
public:
    Game(size_t _board_size);
    ~Game();

    void Start(std::string MODE);
};

#endif