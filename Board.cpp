//
// Created by pshimaf on 31.03.2022.
//

#include <iostream>
#include "Board.h"

Board::Board(std::string whose_move) {
    whose_move_ = whose_move;
    board_ = std::vector<std::vector<Checker>>(8, std::vector<Checker>(8, Checker()));
    Checker red_checker = Checker("red");
    Checker green_checker = Checker("green");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 8; ++j) {
            if ((i + j) % 2 == 0) {
                board_[i][j] = red_checker;
            }
        }
    }
    for (int i = 5; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if ((i + j) % 2 == 0) {
                board_[i][j] = green_checker;
            }
        }
    }
}

void Board::Show() {
    for (int i = 7; i >= 0; --i) {
        for (int j = 0; j < 8; ++j) {
            if (board_[i][j].cost == 0) {
                std::cout << "* ";
            }
            if (board_[i][j].cost > 0) {
                if (board_[i][j].is_queen) {
                    std::cout << "\033[0;31mQ \033[0m";
                } else {
                    std::cout << "\033[0;31mC \033[0m";
                }
            }
            if (board_[i][j].cost < 0) {
                if (board_[i][j].is_queen) {
                    std::cout << "\033[0;32mQ \033[0m";
                } else {
                    std::cout << "\033[0;32mC \033[0m";
                }
            }
        }
        std::cout << '\n';
    }
    std::cout << "\n\n";
}

bool Board::IsCellExist(int line, int column) {
    return ((0 <= line) && (line <= 7) && (0 <= column) && (column <= 7));
}

std::vector<std::pair<int, int>> Board::CanBeat(int line, int column) {
    std::vector<std::pair<int, int>> possible_moves;
    if (board_[line][column].color == "green") {
        if ((IsCellExist(line - 2, column - 2)) &&
        (board_[line - 2][column - 2].color == "empty") &&
        (board_[line - 1][column - 1].color == "red")) {
            possible_moves.emplace_back(line - 2,column - 2);
        }
        if ((IsCellExist(line - 2, column + 2)) &&
            (board_[line - 2][column + 2].color == "empty") &&
            (board_[line - 1][column + 1].color == "red")) {
            possible_moves.emplace_back(line - 2,column + 2);
        }
        if (board_[line][column].is_queen) {
            if ((IsCellExist(line + 2, column - 2)) &&
                (board_[line + 2][column - 2].color == "empty") &&
                (board_[line + 1][column - 1].color == "red")) {
                possible_moves.emplace_back(line + 2,column - 2);
            }
            if ((IsCellExist(line + 2, column + 2)) &&
                (board_[line + 2][column + 2].color == "empty") &&
                (board_[line + 1][column + 1].color == "red")) {
                possible_moves.emplace_back(line + 2,column + 2);
            }
        }
    }
    if (board_[line][column].color == "red") {
        if ((IsCellExist(line + 2, column - 2)) &&
            (board_[line + 2][column - 2].color == "empty") &&
            (board_[line + 1][column - 1].color == "green")) {
            possible_moves.emplace_back(line + 2,column - 2);
        }
        if ((IsCellExist(line + 2, column + 2)) &&
            (board_[line + 2][column + 2].color == "empty") &&
            (board_[line + 1][column + 1].color == "green")) {
            possible_moves.emplace_back(line + 2,column + 2);
        }
        if (board_[line][column].is_queen) {
            if ((IsCellExist(line - 2, column - 2)) &&
                (board_[line - 2][column - 2].color == "empty") &&
                (board_[line - 1][column - 1].color == "green")) {
                possible_moves.emplace_back(line - 2,column - 2);
            }
            if ((IsCellExist(line - 2, column + 2)) &&
                (board_[line - 2][column + 2].color == "empty") &&
                (board_[line - 1][column + 1].color == "green")) {
                possible_moves.emplace_back(line - 2,column + 2);
            }
        }
    }
    return possible_moves;
}

std::string Board::CheckerColor(int line, int column) {
    return board_[line][column].color;
}

std::vector<std::pair<int, int>> Board::CanMoveWithoutBeating(int line, int column) {
    std::vector<std::pair<int, int>> possible_moves;
    if (board_[line][column].color == "green") {
        if ((IsCellExist(line - 1, column - 1)) &&
            (board_[line - 1][column - 1].color == "empty")) {
            possible_moves.emplace_back(line - 1,column - 1);
        }
        if ((IsCellExist(line - 1, column + 1)) &&
            (board_[line - 1][column + 1].color == "empty")) {
            possible_moves.emplace_back(line - 1,column + 1);
        }
        if (board_[line][column].is_queen) {
            if ((IsCellExist(line + 1, column - 1)) &&
                (board_[line + 1][column - 1].color == "empty")) {
                possible_moves.emplace_back(line + 1,column - 1);
            }
            if ((IsCellExist(line + 1, column + 1)) &&
                (board_[line + 1][column + 1].color == "empty")) {
                possible_moves.emplace_back(line + 1,column + 1);
            }
        }
    }
    if (board_[line][column].color == "red") {
        if ((IsCellExist(line + 1, column - 1)) &&
            (board_[line + 1][column - 1].color == "empty")) {
            possible_moves.emplace_back(line + 1,column - 1);
        }
        if ((IsCellExist(line + 1, column + 1)) &&
            (board_[line + 1][column + 1].color == "empty")) {
            possible_moves.emplace_back(line + 1,column + 1);
        }
        if (board_[line][column].is_queen) {
            if ((IsCellExist(line - 1, column - 1)) &&
                (board_[line - 1][column - 1].color == "empty")) {
                possible_moves.emplace_back(line - 1,column - 1);
            }
            if ((IsCellExist(line - 1, column + 1)) &&
                (board_[line - 1][column + 1].color == "empty")) {
                possible_moves.emplace_back(line - 1,column + 1);
            }
        }
    }
    return possible_moves;
}

void Board::Move(std::vector<std::pair<int, int>>& path) {
    if (whose_move_ == "user") {
        whose_move_ = "comp";
    } else {
        whose_move_ = "user";
    }
    if ((path.size() == 2) && ((path[0].first == path[1].first + 1) || (path[0].first == path[1].first - 1))) {
        board_[path[1].first][path[1].second] = board_[path[0].first][path[0].second];
        DeleteChecker(path[0].first, path[0].second);
        if ((board_[path[1].first][path[1].second].color == "green") && (path[1].first == 7)) {
            board_[path[1].first][path[1].second].is_queen = true;
        }
        if ((board_[path[1].first][path[1].second].color == "red") && (path[1].first == 0)) {
            board_[path[1].first][path[1].second].is_queen = true;
        }
        return;
    }
    for (int i = 0; i < path.size() - 1; ++i) {
        board_[path[1].first][path[1].second] = board_[path[0].first][path[0].second];
        DeleteChecker(path[0].first, path[0].second);
        DeleteChecker((path[0].first + path[1].first) / 2, (path[0].second + path[1].second) / 2);
    }
}

void Board::DeleteChecker(int line, int column) {
    board_[line][column].color = "empty";
    board_[line][column].is_queen = false;
    board_[line][column].cost = 0;
}

bool Board::HaveGreenPiece() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board_[i][j].color == "green") {
                return true;
            }
        }
    }
    return false;
}

bool Board::HaveRedPiece() {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board_[i][j].color == "red") {
                return true;
            }
        }
    }
    return false;
}

std::string Board::WhoseMove() {
    return whose_move_;
}