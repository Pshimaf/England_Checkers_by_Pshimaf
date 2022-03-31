//
// Created by pshimaf on 31.03.2022.
//

#include "Checker.h"

Checker::Checker() {
    color = "empty";
    is_queen = false;
    cost = 0;
}

Checker::Checker(std::string color) : is_queen(false) {
    this->color = color;
    if (color == "green") {
        cost = -1;
    }
    if (color == "red") {
        cost = 1;
    }
}

void Checker::MakeQueen() {
    is_queen = true;
    cost *= 4;
}
