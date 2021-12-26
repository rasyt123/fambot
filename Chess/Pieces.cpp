//
// Created by rasyt on 12/21/2021.
//

#include "Pieces.h"


void Chess::Pieces::setcolor(std::string thecolor) {
    color = thecolor;
}


void Chess::Pieces::settype(char thetype) {
    type = thetype;
}

void Chess::Pieces::setblank(bool val) {
    blank = val;
}

std::string Chess::Pieces::getcolor() {
    return color;
}

char Chess::Pieces::gettype() {
    return type;
}

bool Chess::Pieces::getblank() {
    return blank;
}

bool Chess::Pieces::InBounds(int row, int col, std::vector<std::vector<char>>& underboard) {
    return row >= 0 and row <= underboard.size() - 1 and col >= 0 and col <= underboard[0].size() - 1;
}

void Chess::Pieces::clearmoves(std::vector<std::pair<int, int>>& possiblemoves) {
    possiblemoves = {};
}

void Chess::Pieces::addmoves(std::vector<std::pair<int, int>> &src, std::vector<std::pair<int, int>> &destination) {
    for (auto item : src)
    {
        destination.emplace_back(item);
    }
}


