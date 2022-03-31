//
// Created by pshimaf on 31.03.2022.
//

#include <string>

#ifndef MAIN_CPP_CHECKER_H
#define MAIN_CPP_CHECKER_H

class Checker {
public:
    std::string color;
    bool is_queen;
    int cost;

    Checker();
    Checker(std::string color);
    void MakeQueen();
};

#endif //MAIN_CPP_CHECKER_H
