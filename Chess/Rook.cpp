//
// Created by rasyt on 12/22/2021.
//

#include "Rook.h"

bool Chess::Rook::GenerateMoves(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {
    bool topcheck = gettop(underboard, thepieces, color, startposy, startposx);
    bool bottomcheck = getbottom(underboard, thepieces,color, startposy, startposx);
    bool ajleftcheck = getadjacentleft(underboard, thepieces,color, startposy, startposx);
    bool ajrightcheck = getadjacentright(underboard, thepieces, color, startposy, startposx);
    possiblemovescpy = possiblemoves;
    possiblemoves = {};
    if (topcheck or bottomcheck or ajleftcheck or ajrightcheck) 
    {
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

bool Chess::Rook::gettop(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color, int posy, int posx) {
    for (int x = 1; x < underboard.size(); x++)
    {
        if (!InBounds(posy - x, posx, underboard))
        {
            break;
        } else if (underboard[posy - x][posx] == 'A' and thepieces[posy - x][posx].getcolor() != color)
        {
            return true;
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
    return false;
}

bool Chess::Rook::getbottom(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color, int posy, int posx) {
    for (int x = 1; x < underboard.size(); x++)
    {
        if (!InBounds(posy + x, posx, underboard))
        {
            break;
        } else if (underboard[posy + x][posx] == 'A' and thepieces[posy + x][posx].getcolor() != color)
        {
            return true;
        } else if (underboard[posy + x][posx] != ' '
                    and thepieces[posy + x][posx].getcolor() != color)
        {
            possiblemoves.emplace_back(std::make_pair(posy + x, posx));
            break;
        } else
        {
            possiblemoves.emplace_back(std::make_pair(posy + x, posx));
        }
    }
    return false;
}

bool Chess::Rook::getadjacentleft(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color, int posy, int posx) {
    for (int x = 1; x < underboard.size(); x++)
    {
        if (!InBounds(posy, posx - x, underboard))
        {
            break;
        } else if (underboard[posy][posx - x] == 'A' and thepieces[posy][posx - x].getcolor() != color)
        {
            return true;
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
    return false;
}


bool Chess::Rook::getadjacentright(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color, int posy, int posx) {
    for (int x = 1; x < underboard.size(); x++)
    {
        if (!InBounds(posy, posx + x, underboard))
        {
           break;
        } else if (underboard[posy][posx + x] == 'A' and thepieces[posy][posx + x].getcolor() != color)
        {
            return true;
        } else if (underboard[posy][posx + x] != ' '
                    and thepieces[posy][posx + x].getcolor() != color)
        {
            possiblemoves.emplace_back(std::make_pair(posy, posx + x));
            break;
        } else
        {
            possiblemoves.emplace_back(std::make_pair(posy, posx + x));
        }
    }
    return false;
}
