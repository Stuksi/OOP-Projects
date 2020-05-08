#ifndef GAME_H
#define GAME_H

#include "Board.h"

#include <string>
#include <vector>
#include <iostream>

class Game {
private:
    void skipEmptySpaces(std::string& string, size_t &k);
    bool game_over();
    bool correct_command(std::vector<std::string> input_values);
public:
    void Start();
};

#endif