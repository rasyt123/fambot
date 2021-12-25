//
// Created by rasyt on 12/24/2021.
//

#include "Knight.h"


std::vector<std::pair<int,int>> Chess::Knight::getpossiblemoves() {
    return possiblemoves;
}


std::vector<std::pair<int, int>> Chess::Knight::getpossiblemovescpy() {
    return possiblemovescpy;
}

void Chess::Knight::GenerateMoves(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {
    std::vector<std::pair<int, int>> possiblekmoves;
    possiblekmoves = {{startposy - 1, startposx - 2}, {startposy - 2, startposx - 1}, {startposy - 2, startposx + 1},
                      {startposy - 1, startposx + 2}, {startposy + 1, startposx - 2}, {startposy + 2, startposx - 1}, {}};



}