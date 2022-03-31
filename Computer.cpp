//
// Created by pshimaf on 31.03.2022.
//

#include <iostream>
#include "Computer.h"
#include <random>

std::vector<std::pair<int, int>> Computer::GetRandomTurn(Board board) {
    std::vector<std::pair<int, int>> whole_path;
    std::vector<std::vector<std::pair<int, int>>> can_beat;
    std::vector<std::pair<int, int>> can_beat_coordinates;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board.CheckerColor(i, j) == "green") {
                can_beat.push_back(std::move(board.CanBeat(i, j)));
                can_beat_coordinates.emplace_back(i, j);
            }
        }
    }
    int number_of_checkers_that_can_beat = 0;
    std::vector<int> checkers_that_can_beat;
    for (int i = 0; i < can_beat.size(); ++i) {
        if (can_beat[i].empty() > 0) {
            ++number_of_checkers_that_can_beat;
            checkers_that_can_beat.push_back(i);
        }
    }
    std::cout << number_of_checkers_that_can_beat << '\n';
    if (number_of_checkers_that_can_beat > 0) {
        int random_checker = rand();
        random_checker %= number_of_checkers_that_can_beat;
        int chosen_checker_line = can_beat_coordinates[checkers_that_can_beat[random_checker]].first;
        int chosen_checker_column = can_beat_coordinates[checkers_that_can_beat[random_checker]].second;
        whole_path.emplace_back(chosen_checker_line, chosen_checker_column);
        std::vector<std::pair<int, int>> chosen_checker_moves =
                board.CanBeat(chosen_checker_line, chosen_checker_column);
        while (!chosen_checker_moves.empty()) {
            int random_move = rand();
            random_move %= static_cast<int>(chosen_checker_moves.size());
            int move_line = chosen_checker_moves[random_move].first;
            int move_column = chosen_checker_moves[random_move].second;
            std::vector<std::pair<int, int>> path(2);
            path[0].first = chosen_checker_line;
            path[0].second = chosen_checker_column;
            path[1].first = move_line;
            path[1].second = move_column;
            board.Move(path);
            whole_path.emplace_back(move_line, move_column);
            chosen_checker_line = move_line;
            chosen_checker_column = move_column;
            chosen_checker_moves =
                    board.CanBeat(chosen_checker_line, chosen_checker_column);
        }
        return whole_path;
    }
    std::vector<std::vector<std::pair<int, int>>> can_move_without_beating;
    std::vector<std::pair<int, int>> can_move_without_beating_coordinates;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board.CheckerColor(i, j) == "green") {
                can_move_without_beating.push_back(std::move(board.CanMoveWithoutBeating(i, j)));
                can_move_without_beating_coordinates.emplace_back(i, j);
            }
        }
    }
    int number_of_checkers_that_can_move_without_beating = 0;
    std::vector<int> checkers_that_can_move_without_beating;
    for (int i = 0; i < can_move_without_beating.size(); ++i) {
        if (can_move_without_beating[i].empty() > 0) {
            ++number_of_checkers_that_can_move_without_beating;
            checkers_that_can_move_without_beating.push_back(i);
        }
    }
    int random_checker = rand();
    random_checker %= checkers_that_can_move_without_beating.size();
    int chosen_checker_line =
            can_move_without_beating_coordinates[checkers_that_can_move_without_beating[random_checker]].first;
    int chosen_checker_column =
            can_move_without_beating_coordinates[checkers_that_can_move_without_beating[random_checker]].second;
    std::vector<std::pair<int, int>> chosen_checker_moves =
            board.CanMoveWithoutBeating(chosen_checker_line, chosen_checker_column);
    int random_move = rand();
    random_move %= chosen_checker_moves.size();
    whole_path[0].first = chosen_checker_line;
    whole_path[0].second = chosen_checker_column;
    whole_path[1].first = chosen_checker_moves[random_move].first;
    whole_path[1].second = chosen_checker_moves[random_move].second;
    return whole_path;
}
