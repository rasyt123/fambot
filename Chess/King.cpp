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

    if (color == "white" and endposy == 0 and (endposx == startposx - 2 or
    endposx == startposy + 2))
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
        for (int y = 0; y < underboard.size(); y++)
        {
            for (int x = 0; x < underboard[0].size(); x++)
            {
                if (thepieces[y][x].getcolor() == "black")
                {
                    switch (underboard[y][x])
                    {
                        case 'P':
                            pawnobj.GenerateMoves(underboard, thepieces, color);
                            pawnobj.addmoves(pawnobj.getpossiblemoves(), interferemoves);
                            break;
                        case 'R':
                            rookobj.GenerateMoves(underboard, thepieces, color);
                            break;
                        case 'B':
                            bishopobj.GenerateMoves(underboard, thepieces, color);
                            break;
                        case 'Q':
                            queenobj.GenerateMoves(underboard, thepieces, color);
                            break;
                        case 'A':
                            kingobj.GenerateMoves(underboard, thepieces, color);
                            break;
                        case 'K':
                            knightobj.GenerateMoves(underboard, thepieces, color);
                            break;
                        default:
                            break;
                    }
                }
            }
        }

    } else if (color == "black" and endposy == 7 and (endposx == startposx - 2 or endposx ==
    startposy + 2))
    {


    }

    return false;
}


bool Chess::King::determinecheck(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {



}


bool Chess::King::determinecheckmate(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {



}

void Chess::King::generatemoves(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {




}
