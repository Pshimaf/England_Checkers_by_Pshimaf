//
// Created by pshimaf on 31.03.2022.
//

#include <iostream>
#include "Game.h"
#include "Board.h"
#include "Computer.h"

void Game::Run() {
    srand(time(nullptr));
    std::string whose_turn;
    std::cout << "Do you prefer move first or second? (f/s)\n";
    std::cin >> whose_turn;
    if (whose_turn == "f") {
        whose_turn = "user";
    } else {
        whose_turn = "comp";
    }
    Computer comp;
    Board board(whose_turn);
    while (true) {
        board.Show();
        if (board.WhoseMove() == "user") {
            std::cout << "Your Turn\n";
            std::cout << "How much steps in your move\n";
            int steps = 0;
            std::cin >> steps;
            ++steps;
            std::cout << "Write your steps\n";
            std::vector<std::pair<int, int>> path(steps);
            for (int i = 0; i < steps; ++i) {
                std::cin >> path[i].first;
                std::cin >> path[i].second;
                --path[i].first;
                --path[i].second;
            }
            board.Move(path);
        } else {
            auto path = comp.GetRandomTurn(board);
            board.Move(path);
        }
        if (!board.HaveGreenPiece()) {
            std::cout << "YOU LOSE :(\n";
            break;
        }
        if (!board.HaveRedPiece()) {
            std::cout << "YOU WIN :)\n";
            break;
        }
    }
    board.Show();

}
