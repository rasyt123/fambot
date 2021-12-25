//
// Created by rasyt on 12/22/2021.
//

#include "Bishop.h"


bool Chess::Bishop::GenerateMoves(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {
    grabmovetopleft(underboard, thepieces, color, startposy, startposx);
    grabmovetopright(underboard, thepieces,color, startposy, startposx);
    grabmovebottomleft(underboard, thepieces,color, startposy, startposx);
    grabmovebottomright(underboard, thepieces, color, startposy, startposx);
    possiblemovescpy = possiblemoves;
    possiblemoves = {};

    grabmovetopleft(underboard, thepieces, color, endposy, endposx);
    grabmovetopright(underboard, thepieces,color, endposy, endposx);
    grabmovebottomleft(underboard, thepieces,color, endposy, endposx);
    grabmovebottomright(underboard, thepieces, color, endposy, endposx);
    if (hasking) {
        return true;
    }
    return false;
}


bool Chess::Bishop::IsValidMove(int rows, int cols) {
    for (std::pair<int, int> coordpair : possiblemoves)
    {
        if (rows == coordpair.first and cols == coordpair.second)
        {
            return true;
        }
    }
    return false;
}

std::vector<std::pair<int,int>> Chess::Bishop::getpossiblemoves() {
    return possiblemoves;
}


std::vector<std::pair<int, int>> Chess::Bishop::getpossiblemovescpy() {
    return possiblemovescpy;
}


void Chess::Bishop::grabmovetopleft(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color, int posy, int posx) {
    for (int x = 1; x < underboard.size(); x++)
    {
        if (!InBounds(posy - x, posx - x, underboard) or
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
}


void Chess::Bishop::grabmovetopright(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color, int posy, int posx) {
    for (int x = 1; x < underboard.size(); x++)
    {
        if (!InBounds(posy - x, posx + x, underboard) or
            underboard[posy - x][posx + x] == 'A' and thepieces[posy - x][posx + x].getcolor() != color)
        {
            hasking = true;
            break;
        }  else if (underboard[posy - x][posx + x] != ' '
                    and thepieces[posy - x][posx + x].getcolor() != color)
        {
            possiblemoves.emplace_back(std::make_pair(posy - x, posx + x));
            break;
        } else
        {
            possiblemoves.emplace_back(std::make_pair(posy - x, posx + x));
        }
    }
}

void Chess::Bishop::grabmovebottomleft(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color, int posy, int posx) {
    for (int x = 1; x < underboard.size(); x++)
    {
        if (!InBounds(posy + x, posx - x, underboard) or
            underboard[posy + x][posx - x] == 'A' and thepieces[posy + x][posx - x].getcolor() != color)
        {
            hasking = true;
            break;
        }  else if (underboard[posy + x][posx - x] != ' '
                    and thepieces[posy + x][posx - x].getcolor() != color)
        {
            possiblemoves.emplace_back(std::make_pair(posy + x, posx - x));
            break;
        } else
        {
            possiblemoves.emplace_back(std::make_pair(posy + x, posx - x));
        }
    }
}


void Chess::Bishop::grabmovebottomright(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color, int posy, int posx) {
    for (int x = 1; x < underboard.size(); x++)
    {
        if (!InBounds(posy + x, posx + x, underboard) or
            underboard[posy + x][posx + x] == 'A' and thepieces[posy + x][posx + x].getcolor() != color)
        {
            hasking = true;
            break;
        }  else if (underboard[posy + x][posx + x] != ' '
                    and thepieces[posy + x][posx + x].getcolor() != color)
        {
            possiblemoves.emplace_back(std::make_pair(posy + x, posx + x));
            break;
        } else
        {
            possiblemoves.emplace_back(std::make_pair(posy + x, posx + x));
        }
    }
}




