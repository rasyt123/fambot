//
// Created by rasyt on 12/22/2021.
//
#include "Pawn.h"


void Chess::Pawn::GenerateMoves(sf::RenderWindow* window, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string turn) {
    if (turn == "white") {
        GenerateWhite(underboard);

    } else {
        GenerateBlack(underboard);
    }
}

bool Chess::Pawn::IsValidMove(int row, int col) {
    for (std::pair<int, int> coordpair : possiblemoves) {
        if (row == coordpair.first and col == coordpair.second) {
            return true;
        }

    }
    return false;
}

bool Chess::Pawn::InBounds(int row, int col, std::vector<std::vector<char>>& underboard) {
    return row >= 0 and row <= underboard.size() - 1 and col >= 0 and col <= underboard[0].size() - 1;
}

void Chess::Pawn::GenerateWhite(std::vector<std::vector<char>>& underboard) {
    if (BottomLeft(underboard)) {
        possiblemoves.push_back(std::make_pair(startposy + 1, startposx - 1));
    }
    if (BottomRight(underboard)) {
        possiblemoves.push_back(std::make_pair(startposy + 1, startposx + 1));
    }
    if (infrontdown(underboard)) {
        possiblemoves.push_back(std::make_pair(startposy + 1, startposx))
    }
    if (infront2down(underboard)) {
        possiblemoves.push_back(std::make_pair(startposy + 2, startposx));
    }
}

void Chess::Pawn::GenerateBlack(std::vector<std::vector<char>> &underboard) {
    if (TopLeft(underboard)) {
        possiblemoves.push_back(std::make_pair(startposy-1, startposx-1));
    }
    if (TopRight(underboard)) {
        possiblemoves.push_back(std::make_pair(startposy-1, startposx+1));
    }
    if (infronttop(underboard)) {
        possiblemoves.push_back(std::make_pair(startposy-1, startposx));
    }
    if (infront2top(underboard)) {
        possiblemoves.push_back(std::make_pair(startposy-2, startposx));
    }
}

bool Chess::Pawn::BottomLeft(std::vector<std::vector<char>>& underboard) {
    return InBounds(startposy+1, startposx-1, underboard) and underboard[startposy + 1][startposx - 1] != ' ';
}

bool Chess::Pawn::BottomRight(std::vector<std::vector<char>>& underboard) {
    return InBounds(startposy+1, startposx+1, underboard) and underboard[startposy + 1][startposx + 1] != ' ';
}

bool Chess::Pawn::infrontdown(std::vector<std::vector<char>> &underboard) {
    return InBounds(startposy+1, startposx, underboard) and underboard[startposy + 1][startposx] == ' ';
}

bool Chess::Pawn::infront2down(std::vector<std::vector<char>> &underboard) {
    return startposy == 1 and InBounds(startposy+2, startposx, underboard) and underboard[startposy + 2][startposx] == ' ';
}

bool Chess::Pawn::TopLeft(std::vector<std::vector<char>> &underboard) {
    return InBounds(startposy-1, startposx-1, underboard) and underboard[startposy - 1][startposx - 1] != ' ';
}

bool Chess::Pawn::TopRight(std::vector<std::vector<char>> &underboard) {
    return InBounds(startposy-1, startposx + 1, underboard) and underboard[startposy - 1][startposx + 1];
}

bool Chess::Pawn::infronttop(std::vector<std::vector<char>> &underboard) {
    return InBounds(startposy-1, startposx, underboard) and underboard[startposy - 1][startposx] == ' ';
}

bool Chess::Pawn::infront2top(std::vector<std::vector<char>> &underboard) {
    return startposy == 6 and InBounds(startposy-2, startposx, underboard) and underboard[startposy - 2][startposx] == ' ';
}


void Chess::Pawn::EnPassant(sf::RenderWindow* window, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string turn) {




}


void Chess::Pawn::Capture(sf::RenderWindow* window, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string turn) {
    char oldpiece = underboard[startposy][startposx];
    underboard[startposy][startposx] = ' ';
    underboard[endposy][endposx] = oldpiece;
    thepieces[endposy][endposx] = thepieces[startposy][startposx];
    thepieces[startposy][startposx].settype(' ');
    thepieces[startposy][startposx].setblank(true);
    thepieces[startposy][startposx].setcolor("");
}


void Chess::Pawn::ListPromotionOptions(sf::RenderWindow* window, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string turn) {






}
