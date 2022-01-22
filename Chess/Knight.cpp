//
// Created by rasyt on 12/24/2021.
//

#include "Knight.h"


std::vector<std::pair<int,int>>& Chess::Knight::getpossiblemoves() {
    return possiblemoves;
}


std::vector<std::pair<int, int>> Chess::Knight::getpossiblemovescpy() {
    return possiblemovescpy;
}


bool Chess::Knight::GenerateMoves(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {
    std::vector<std::pair<int, int>> possiblekmoves;
    bool incheck = false;
    possiblekmoves = {{startposy - 1, startposx - 2}, {startposy - 2, startposx - 1}, {startposy - 2, startposx + 1},
                      {startposy - 1, startposx + 2}, {startposy + 1, startposx - 2}, {startposy + 2, startposx - 1}, {startposy + 2, startposx + 1},
                      {startposy + 1, startposx + 2}};
    for (std::pair<int, int> horsemove : possiblekmoves)
    {
        if (InBounds(horsemove.first, horsemove.second, underboard) and
                (thepieces[horsemove.first][horsemove.second].getcolor() != color or underboard[horsemove.first][horsemove.second] == ' '))
        {
            if (underboard[horsemove.first][horsemove.second] == 'A')
            {
                incheck = true;
                starekingdown = true;
            } else
            {
                possiblemoves.emplace_back(std::make_pair(horsemove.first, horsemove.second));
            }

        }

    }
    return incheck;
}


bool Chess::Knight::getstaredown() {
    return starekingdown;
}