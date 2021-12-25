//
// Created by rasyt on 12/22/2021.
//

#include "Rook.h"

bool Chess::Rook::GenerateMoves(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {
    gettop(underboard, thepieces, color, startposy, startposx);
    getbottom(underboard, thepieces,color, startposy, startposx);
    getadjacentleft(underboard, thepieces,color, startposy, startposx);
    getadjacentright(underboard, thepieces, color, startposy, startposx);
    possiblemovescpy = possiblemoves;
    possiblemoves = {};

    gettop(underboard, thepieces, color, endposy, endposx);
    getbottom(underboard, thepieces,color, endposy, endposx);
    getadjacentleft(underboard, thepieces,color, endposy, endposx);
    getadjacentright(underboard, thepieces, color, endposy, endposx);
    if (hasking) {
        return true;
    }
    return false;
}


std::vector<std::pair<int,int>> Chess::Rook::getpossiblemoves() {
    return possiblemoves;
}


std::vector<std::pair<int, int>> Chess::Rook::getpossiblemovescpy() {
    return possiblemovescpy;
}

void Chess::Rook::gettop(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color, int posy, int posx) {
    for (int x = 1; x < underboard.size(); x++)
    {
        if (!InBounds(posy - x, posx, underboard) or
            (underboard[posy - x][posx] == 'A' and thepieces[posy - x][posx].getcolor() != color))
        {
            hasking = true;
            break;
        }  else if (underboard[posy - x][posx] != ' '
                    and thepieces[posy - x][posx].getcolor() != color)
        {
            possiblemoves.emplace_back(std::make_pair(posy - x, posx));
            break;
        } else
        {
            possiblemoves.emplace_back(std::make_pair(posy - x, posx));
        }
    }
}

void Chess::Rook::getbottom(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color, int posy, int posx) {
    for (int x = 1; x < underboard.size(); x++)
    {
        if (!InBounds(posy + x, posx, underboard) or
            (underboard[posy + x][posx] == 'A' and thepieces[posy + x][posx].getcolor() != color))
        {
            hasking = true;
            break;
        }  else if (underboard[posy + x][posx] != ' '
                    and thepieces[posy + x][posx].getcolor() != color)
        {
            possiblemoves.emplace_back(std::make_pair(posy + x, posx));
            break;
        } else
        {
            possiblemoves.emplace_back(std::make_pair(posy + x, posx));
        }
    }

}

void Chess::Rook::getadjacentleft(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color, int posy, int posx) {
    for (int x = 1; x < underboard.size(); x++)
    {
        if (!InBounds(posy, posx - x, underboard) or
            (underboard[posy][posx - x] == 'A' and thepieces[posy][posx - x].getcolor() != color))
        {
            hasking = true;
            break;
        }  else if (underboard[posy][posx - x] != ' '
                    and thepieces[posy][posx - x].getcolor() != color)
        {
            possiblemoves.emplace_back(std::make_pair(posy, posx - x));
            break;
        } else
        {
            possiblemoves.emplace_back(std::make_pair(posy, posx - x));
        }
    }
}


void Chess::Rook::getadjacentright(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color, int posy, int posx) {
    for (int x = 1; x < underboard.size(); x++)
    {
        if (!InBounds(posy, posx + x, underboard) or
            (underboard[posy][posx + x] == 'A' and thepieces[posy][posx + x].getcolor() != color))
        {
            hasking = true;
            break;
        }  else if (underboard[posy][posx + x] != ' '
                    and thepieces[posy][posx + x].getcolor() != color)
        {
            possiblemoves.emplace_back(std::make_pair(posy, posx + x));
            break;
        } else
        {
            possiblemoves.emplace_back(std::make_pair(posy, posx + x));
        }
    }
}