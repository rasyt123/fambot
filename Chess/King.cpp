//
// Created by rasyt on 12/22/2021.
//

#include "King.h"


void Chess::King::CastleMovement(std::vector<std::vector<char>> &underboard,
                                 std::vector<std::vector<Pieces>> &thepieces, std::string color) {





}


void Chess::King::GenerateMoves(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {



}

bool Chess::King::performCastle(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {
    bool cancastle = false;
    bool qsidecastle = false;
    bool qsidehrook = false;

    bool ksinghrook = false;
    bool kingsidecastle = true;
    Pawn pawnobj;
    Rook rookobj;
    Queen queenobj;
    Bishop bishopobj;
    King kingobj;
    Knight knightobj;
    std::vector<std::pair<int, int>> wqsidecoords = {{startposy, startposx - 1}, {startposy, startposx - 2}, {startposy, startposx - 3}};
    std::vector<std::pair<int, int>> wkingsidecoords = {{startposy, startposx + 1}, {startposy, startposx + 2}};
    std::vector<std::pair<int, int>> bqsidecoords;
    std::vector<std::pair<int, int>> bkingsidecoords;

    if (color == "white" and endposy == 0 and (endposx == startposx - 2 or
    endposx == startposx + 2))
    {
        if (InBounds(startposy, startposx - 4, underboard) and underboard[startposy][startposy - 4] == 'R'
        and thepieces[startposy][startposx - 4].getcolor() == "white")
        {
            qsidehrook = true;
        }
        if (InBounds(startposy, startposx + 3, underboard) and underboard[startposy][startposx + 3] == 'R'
        and thepieces[startposy][startposx + 4].getcolor() == "white")
        {
            ksinghrook = true;
        }
        if (endposx == startposx - 2)
        {
            for (int xbet = startposx; xbet >= 1; xbet--)
            {
                if (underboard[startposx][xbet] != ' ')
                {
                    return false;
                }

            }
        }
        if (endposx == startposx + 2)
        {
            for (int xbet = startposx; xbet <= endposx; xbet++)
            {
                if (underboard[startposx][xbet] != ' ')
                {
                    return false;
                }
            }

        }
        for (int y = 0; y < underboard.size(); y++)
        {
            for (int x = 0; x < underboard[0].size(); x++)
            {
                if (thepieces[y][x].getcolor() == "black" and underboard[y][x] != ' ')
                {
                    collectmoveinterference(underboard, thepieces, pawnobj, rookobj, queenobj, bishopobj, kingobj,
                                            knightobj, y, x, color);
                }
            }
        }

        for (std::pair<int, int> move : interferemoves)
        {
            if (endposx == startposx - 2)
            {
                for (std::pair<int, int> item : wqsidecoords) 
                {
                    if (move == item) 
                    {
                        return false;
                    }
                }
                
            } else if (endposx == startposx + 2)
            {
                for (std::pair<int, int> item : wkingsidecoords) 
                {
                    if (move == item) 
                    {
                        return false;
                    }
                }

            }

        }

    } else if (color == "black" and endposy == 7 and (endposx == startposx - 2 or endposx ==
    startposx + 2))
    {


    }

    return false;
}


void Chess::King::collectmoveinterference(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, Pawn& pawnobj, Rook& rookobj, Queen& queenobj,
                             Bishop& bishopobj, King& kingobj, Knight& knightobj, int y, int x, std::string color) {
    switch (underboard[y][x])
    {
        case 'P':
            pawnobj.GenerateMoves(underboard, thepieces, color);
            this->addmoves(pawnobj.getpossiblemoves(), interferemoves);
            break;
        case 'R':
            rookobj.GenerateMoves(underboard, thepieces, color);
            this->addmoves(rookobj.getpossiblemoves(), interferemoves);
            break;
        case 'B':
            bishopobj.GenerateMoves(underboard, thepieces, color);
            this->addmoves(bishopobj.getpossiblemoves(), interferemoves);
            break;
        case 'Q':
            queenobj.GenerateMoves(underboard, thepieces, color);
            this->addmoves(queenobj.getpossiblemoves(), interferemoves);
            break;
        case 'A':
            kingobj.GenerateMoves(underboard, thepieces, color);
            this->addmoves(queenobj.getpossiblemoves(), interferemoves);
            break;
        case 'K':
            knightobj.GenerateMoves(underboard, thepieces, color);
            this->addmoves(knightobj.getpossiblemoves(), interferemoves);
            break;
        default:
            break;
    }


}

void Chess::King::addmoves(std::vector<std::pair<int, int>> src, std::vector<std::pair<int, int>> &destination) {
    for (auto item : src)
    {
        destination.emplace_back(item);
    }
}


bool Chess::King::determinecheck(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {



}


bool Chess::King::determinecheckmate(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {



}

void Chess::King::generatemoves(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {




}
