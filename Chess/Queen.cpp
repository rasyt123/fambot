//
// Created by rasyt on 12/22/2021.
//

#include "Queen.h"

std::vector<std::pair<int,int>> Chess::Rook::getpossiblemoves() {
    return possiblemoves;
}


std::vector<std::pair<int, int>> Chess::Rook::getpossiblemovescpy() {
    return possiblemovescpy;
}

void Chess::Queen::GenerateMoves(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {
    bishopmethod.GenerateMoves(underboard, thepieces, color);
    rookmethod.GenerateMoves(underboard, thepieces, color);
    for (auto moves : rookmethod.getpossiblemovescpy())
    {
        bishopmethod.getpossiblemovescpy().push_back(moves);
    }
    possiblemovescpy = bishopmethod.getpossiblemovescpy();
}

