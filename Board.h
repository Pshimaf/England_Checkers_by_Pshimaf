//
// Created by pshimaf on 31.03.2022.
//

#include <vector>
#include "Checker.h"

#ifndef MAIN_CPP_BOARD_H
#define MAIN_CPP_BOARD_H

class Board {
public:
    Board(std::string whose_move);
    void Show();
    bool IsCellExist(int line, int column);
    std::vector<std::pair<int, int>> CanBeat(int line, int column);
    std::vector<std::pair<int, int>> CanMoveWithoutBeating(int line, int column);
    void Move(std::vector<std::pair<int, int>>& path);
    void DeleteChecker(int line, int column);
    std::string CheckerColor(int line, int column);
    bool HaveGreenPiece();
    bool HaveRedPiece();
    std::string WhoseMove();

private:
    std::string whose_move_;
    std::vector<std::vector<Checker>> board_;
};

#endif //MAIN_CPP_BOARD_H
