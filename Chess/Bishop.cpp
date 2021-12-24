//
// Created by rasyt on 12/22/2021.
//

#include "Bishop.h"


bool Chess::Bishop::GenerateMoves(sf::RenderWindow* window, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {
    grabmovetopleft(underboard, thepieces, color);
    grabmovetopright(underboard, thepieces,color);
    grabmovebottomleft(underboard, thepieces,color);
    grabmovebottomright(underboard, thepieces, color);


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


void Chess::Bishop::grabmovetopleft(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {
    for (int x = 1; x < underboard.size(); x++)
    {
        if (!InBounds(startposy - x, startposx - x, underboard) or
            underboard[startposy - x][startposx - x] == 'A')
        {
            break;
        }  else if (underboard[startposy - x][startposx - x] != ' '
                    and thepieces[startposy - x][startposx - x].getcolor() != color)
        {
            possiblemoves.emplace_back(std::make_pair(startposy - x, startposx - x));
            break;
        } else
        {
            possiblemoves.emplace_back(std::make_pair(startposy - x, startposx - x));
        }
    }
}


void Chess::Bishop::grabmovetopright(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {
    for (int x = 1; x < underboard.size(); x++)
    {
        if (!InBounds(startposy - x, startposx + x, underboard) or
            underboard[startposy - x][startposx + x] == 'A')
        {
            break;
        }  else if (underboard[startposy - x][startposx + x] != ' '
                    and thepieces[startposy - x][startposx + x].getcolor() != color)
        {
            possiblemoves.emplace_back(std::make_pair(startposy - x, startposx + x));
            break;
        } else
        {
            possiblemoves.emplace_back(std::make_pair(startposy - x, startposx + x));
        }
    }
}

void Chess::Bishop::grabmovebottomleft(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {
    for (int x = 1; x < underboard.size(); x++)
    {
        if (!InBounds(startposy + x, startposx - x, underboard) or
            underboard[startposy + x][startposx - x] == 'A')
        {
            break;
        }  else if (underboard[startposy + x][startposx - x] != ' '
                    and thepieces[startposy + x][startposx - x].getcolor() != color)
        {
            possiblemoves.emplace_back(std::make_pair(startposy + x, startposx - x));
            break;
        } else
        {
            possiblemoves.emplace_back(std::make_pair(startposy + x, startposx - x));
        }
    }
}


void Chess::Bishop::grabmovebottomright(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {
    for (int x = 1; x < underboard.size(); x++)
    {
        if (!InBounds(startposy + x, startposx + x, underboard) or
            underboard[startposy + x][startposx + x] == 'A')
        {
            break;
        }  else if (underboard[startposy + x][startposx + x] != ' '
                    and thepieces[startposy + x][startposx + x].getcolor() != color)
        {
            possiblemoves.emplace_back(std::make_pair(startposy + x, startposx + x));
            break;
        } else
        {
            possiblemoves.emplace_back(std::make_pair(startposy + x, startposx + x));
        }
    }
}









