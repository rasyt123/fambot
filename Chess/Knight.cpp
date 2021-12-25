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
                      {startposy - 1, startposx + 2}, {startposy + 1, startposx - 2}, {startposy + 2, startposx - 1}, {startposy + 2, startposx + 1},
                      {startposy + 1, startposx + 2}};
    for (std::pair<int, int> horsemove : possiblekmoves)
    {
        if (InBounds(horsemove.first, horsemove.second) and underboard[horsemove.first][horsemove.second] and
        thepieces[horsemove.first][horsemove.second].getcolor() != color)
        {
            if ()
            hasking = true;

        }

    }
/*
 *
 *
 * if (!InBounds(posy - x, posx - x, underboard) or
                (underboard[posy - x][posx - x] == 'A' and thepieces[posy - x][posx - x].getcolor() != color))
        {
            hasking = true;
            break;
        }  else if (underboard[posy - x][posx - x] != ' '
                    and thepieces[posy - x][posx - x].getcolor() != color)
        {
            possiblemoves.emplace_back(std::make_pair(posy - x, posx - x));
            break;
        } else
        {
            possiblemoves.emplace_back(std::make_pair(posy - x, posx - x));
        }
    }
 */


}
