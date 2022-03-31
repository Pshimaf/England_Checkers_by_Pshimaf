cmake_minimum_required(VERSION 3.21)
project(OneC)

set(CMAKE_CXX_STANDARD 20)

add_executable(OneC main.cpp Checker.h Checker.cpp Board.cpp Board.h Game.cpp Game.h Computer.cpp Computer.h)
