//
// Created by pshimaf on 31.03.2022.
//

#ifndef MAIN_CPP_COMPUTER_H
#define MAIN_CPP_COMPUTER_H

#include "Board.h"

class Computer {
public:
    std::vector<std::pair<int, int>> GetRandomTurn(Board board);
};

#endif //MAIN_CPP_COMPUTER_H
