//
// Created by rasyt on 12/22/2021.
//

#include "King.h"


void Chess::King::CastleMovement(std::vector<std::vector<char>> &underboard,
                                 std::vector<std::vector<Pieces>> &thepieces) {
    if (endposy == 0 and endposx == startposx - 2)
    {
        castleenact();
    } else if (endposy == 0 and endposx == startposx + 2)
    {
        castleenact();
    } else if (endposy == 7 and endposx == startposx - 2)
    {
        castleenact();
    } else if (endposy == 7 and endposx == startposx + 2)
    {
        castleenact();
    }
}


void Chess::King::GenerateMoves(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {



}


void Chess::King::castleenact(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, int startposfactor, int kingcrement) {
    char temprook = underboard[endposy][startposfactor];
    Pieces tpiecer = thepieces[endposy][startposfactor];
    setblank(endposy, startposx - 3, underboard, thepieces);
    char tempking = underboard[startposy][startposx];
    Pieces tpiecek = thepieces[startposy][startposx];
    setblank(startposy, startposx, underboard, thepieces);
    underboard[endposy][endposx] = tempking;
    thepieces[endposy][endposx] = tpiecek;
    underboard[endposy][kingcrement] = temprook;
    thepieces[endposy][kingcrement] = tpiecek;
    
}

void Chess::King::setblank(int ypos, int xpos, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces) {
    underboard[ypos][xpos] = ' ';
    thepieces[ypos][xpos].setblank(true);
    thepieces[ypos][xpos].setcolor(" ");
    thepieces[ypos][xpos].settype(' ');
}

bool Chess::King::performCastle(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {

    if (color == "black" and endposy == 0 and (endposx == startposx - 2 or
    endposx == startposx + 2))
    {
         if (CastleCheck(underboard, thepieces, color))
         {
             CastleMovement(underboard, thepieces, color);
             return true;
         }
    } else if (color == "white" and endposy == 7 and (endposx == startposx - 2 or endposx ==
    startposx + 2))
    {
        if (CastleCheck(underboard, thepieces, color))
        {
            CastleMovement(underboard, thepieces, color);
            return true;
        }
    }

    return false;
}


bool Chess::King::CastleCheck(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {
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
    bool qsidehrook = false;
    bool ksinghrook = false;
    if (InBounds(startposy, startposx - 4, underboard) and underboard[startposy][startposy - 4] == 'R'
        and thepieces[startposy][startposx - 4].getcolor() == color)
    {
        qsidehrook = true;
    }
    if (InBounds(startposy, startposx + 3, underboard) and underboard[startposy][startposx + 3] == 'R'
        and thepieces[startposy][startposx + 4].getcolor() == color)
    {
        ksinghrook = true;
    }
    if (endposx == startposx - 2)
    {
        if (!qsidehrook)
        {
            return false;
        }
        for (int xbet = startposx; xbet >= 1; xbet--)
        {
            if (underboard[startposy][xbet] != ' ')
            {
                return false;
            }

        }
    }
    if (endposx == startposx + 2)
    {
        if (!ksinghrook)
        {
            return false;
        }
        for (int xbet = startposx; xbet <= endposx; xbet++)
        {
            if (underboard[startposy][xbet] != ' ')
            {
                return false;
            }
        }

    }
    for (int y = 0; y < underboard.size(); y++)
    {
        for (int x = 0; x < underboard[0].size(); x++)
        {
            if (thepieces[y][x].getcolor() != color and underboard[y][x] != ' ')
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
    return true;
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

