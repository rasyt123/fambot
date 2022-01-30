//
// Created by rasyt on 12/22/2021.
//

#include "King.h"


void Chess::King::CastleMovement(std::vector<std::vector<char>> &underboard,
                                 std::vector<std::vector<Pieces>> &thepieces) {
    if ((endposy == 7 or endposy == 0) and endposx == startposx - 2)
    {
        castleenact(underboard, thepieces, startposx - 4, endposx + 1);
    } else if ((endposy == 7 or endposy == 0) and endposx == startposx + 2)
    {
        castleenact(underboard, thepieces, startposx + 3, endposx - 1);
    }
}



void Chess::King::GenerateMoves(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {
    //top left, topright, uptop,
    //8 different directions.
    //for each of the direction coordinates, check if an opposing colored piece is watching the direction
    //if it isn't, we can push the move into the vector.

    std::vector<std::pair<int, int>> dirs = {{startposy - 1, startposx - 1}, {startposy - 1, startposx}, {startposy - 1, startposx + 1}, {startposy, startposx - 1}, {startposy, startposx + 1},
                                             {startposy + 1, startposx - 1}, {startposy + 1, startposx}, {startposy + 1, startposx + 1}};
    for (int y = 0; y < underboard.size(); y++)
    {
        for (int x = 0; x < underboard[0].size(); x++)
        {
            if (thepieces[y][x].getcolor() != color and underboard[y][x] != ' ')
            {
                collectmoveinterference(underboard, thepieces, y, x, thepieces[y][x].getcolor());
            }
        }
    }
    for (std::pair<int, int> item : dirs)
    {
        //king cannot eat protected pieces
        if (InBounds(item.first, item.second, underboard) and std::find(interferemoves.begin(), interferemoves.end(), item) == interferemoves.end()
        and (underboard[item.first][item.second] == ' ' or (thepieces[item.first][item.second].getcolor() != color and underboard[item.first][item.second] != 'A'))) {
            possiblemoves.emplace_back(item);
        }
    }
}


void Chess::King::castleenact(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, int startposfactor, int kingcrement) {
    char temprook = underboard[endposy][startposfactor];
    Pieces tpiecer = thepieces[endposy][startposfactor];
    setblank(endposy, startposfactor, underboard, thepieces);
    char tempking = underboard[startposy][startposx];
    Pieces tpiecek = thepieces[startposy][startposx];
    setblank(startposy, startposx, underboard, thepieces);
    underboard[endposy][endposx] = tempking;
    thepieces[endposy][endposx] = tpiecek;
    underboard[endposy][kingcrement] = temprook;
    thepieces[endposy][kingcrement] = tpiecer;

}

void Chess::King::setblank(int ypos, int xpos, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces) {
    underboard[ypos][xpos] = ' ';
    thepieces[ypos][xpos].setblank(true);
    thepieces[ypos][xpos].setcolor(" ");
    thepieces[ypos][xpos].settype(' ');
}

bool Chess::King::performCastle(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {
    if (color == "black" and endposy == 0 and (endposx == startposx - 2 or
    endposx == startposx + 2) and startposy == 0 and startposx == 4)
    {
         if (CastleCheck(underboard, thepieces, color))
         {
             CastleMovement(underboard, thepieces);
             return true;
         }
    } else if (color == "white" and endposy == 7 and (endposx == startposx - 2 or endposx ==
    startposx + 2) and startposy == 7 and startposx == 4)
    {
        if (CastleCheck(underboard, thepieces, color))
        {
            CastleMovement(underboard, thepieces);
            return true;
        }
    }

    return false;
}


bool Chess::King::CastleCheck(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {
    std::vector<std::pair<int, int>> wqsidecoords = {{startposy, startposx - 1}, {startposy, startposx - 2}, {startposy, startposx - 3}};
    std::vector<std::pair<int, int>> wkingsidecoords = {{startposy, startposx + 1}, {startposy, startposx + 2}};
    std::vector<std::pair<int, int>> bqsidecoords;
    std::vector<std::pair<int, int>> bkingsidecoords;
    bool qsidehrook = false;
    bool ksinghrook = false;
    if (InBounds(startposy, startposx - 4, underboard) and underboard[startposy][startposx - 4] == 'R'
        and thepieces[startposy][startposx - 4].getcolor() == color)
    {
        qsidehrook = true;
    }
    if (InBounds(startposy, startposx + 3, underboard) and underboard[startposy][startposx + 3] == 'R'
        and thepieces[startposy][startposx + 3].getcolor() == color)
    {
        ksinghrook = true;
    }
    if (endposx == startposx - 2)
    {
        if (!qsidehrook)
        {
            return false;
        }
        for (int xbet = startposx - 1; xbet >= 1; xbet--)
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
        for (int xbet = startposx + 1; xbet <= endposx; xbet++)
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
                collectmoveinterference(underboard, thepieces, y, x, thepieces[y][x].getcolor());
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



bool Chess::King::collectmoveinterference(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, int y, int x, std::string color) {
    //whitew
    Pawn pawnobj(x, y, -9000, -9000);
    Rook rookobj(x, y, -9000, -9000);
    Queen queenobj(x, y, -9000, -9000);
    Bishop bishopobj(x, y, -9000, -9000);
    King kingobj(x, y, -9000, -9000);
    Knight knightobj(x, y, -9000, -9000);
    switch (underboard[y][x])
    {
        case 'P':
            pawnobj.GenerateMoves(underboard, thepieces, color);
            if (pawnobj.getstaredown())
            {
                std::cout << "Pawn stare down" << std::endl;
                return true;
            }
            this->addmoves(pawnobj.getwatchingsquares(), interferemoves);
            break;
        case 'R':
            rookobj.GenerateMoves(underboard, thepieces, color);
            if (rookobj.getstaredown())
            {
                currstarekingy = rookobj.getstaredownkingy();
                currstarekingx = rookobj.getstaredownkingx();
                std::cout << "Rook stare down" << std::endl;
                return true;
            }
            this->addmoves(rookobj.getpossiblemoves(), interferemoves);
            break;
        case 'B':
            bishopobj.GenerateMoves(underboard, thepieces, color);
            if (bishopobj.getstaredown())
            {
                currstarekingy = bishopobj.getstaredownkingy();
                currstarekingx = bishopobj.getstaredownkingx();
                std::cout << "bishop stare down" << std::endl;
                return true;
            }
            this->addmoves(bishopobj.getpossiblemoves(), interferemoves);
            break;
        case 'Q':
            queenobj.GenerateMoves(underboard, thepieces, color);
            if (queenobj.getstaredown())
            {
                currstarekingy = queenobj.getstaredownkingy();
                currstarekingx = queenobj.getstaredownkingx();
                std::cout << "queen stare down" << std::endl;
                return true;
            }
            this->addmoves(queenobj.getpossiblemoves(), interferemoves);
            break;
        case 'K':
            knightobj.GenerateMoves(underboard, thepieces, color);
            if (knightobj.getstaredown())
            {
                std::cout << "knight stare down" << std::endl;
                return true;
            }
            this->addmoves(knightobj.getpossiblemoves(), interferemoves);
            break;
        default:
            break;
    }
    return false;
}


void Chess::King::collectmoveinterference2(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, int y, int x, std::string color) {
    Pawn pawnobj(x, y, -9000, -9000);
    Rook rookobj(x, y, -9000, -9000);
    Queen queenobj(x, y, -9000, -9000);
    Bishop bishopobj(x, y, -9000, -9000);
    King kingobj(x, y, -9000, -9000);
    Knight knightobj(x, y, -9000, -9000);
    switch (underboard[y][x])
    {
        case 'P':
            pawnobj.GenerateMoves(underboard, thepieces, color);
            break;
        case 'R':
            this->addmoves(rookobj.getpossiblemoves(), interferemoves2);
            break;
        case 'B':
            bishopobj.GenerateMoves(underboard, thepieces, color);
            this->addmoves(bishopobj.getpossiblemoves(), interferemoves2);
            break;
        case 'Q':
            queenobj.GenerateMoves(underboard, thepieces, color);
            this->addmoves(queenobj.getpossiblemoves(), interferemoves2);
            break;
        case 'K':
            knightobj.GenerateMoves(underboard, thepieces, color);
            this->addmoves(knightobj.getpossiblemoves(), interferemoves2);
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

std::vector<std::pair<int,int>> Chess::King::getpossiblemoves() {
    return possiblemoves;
}


bool Chess::King::determinecheck(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {
    for (int y = 0; y < underboard.size(); y++)
    {
        for (int x = 0; x < underboard[0].size(); x++)
        {
            if (thepieces[y][x].getcolor() != color and underboard[y][x] != ' ' and underboard[y][x] != 'A')
            {
                if (collectmoveinterference(underboard, thepieces, y, x, thepieces[y][x].getcolor())) {
                    return true;
                }
            }
        }
    }
    return false;
}

std::vector<int> Chess::King::grabstaredown(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {
    for (int y = 0; y < underboard.size(); y++)
    {
        for (int x = 0; x < underboard[0].size(); x++)
        {
            if (thepieces[y][x].getcolor() != color and underboard[y][x] != ' ' and underboard[y][x] != 'A')
            {
                if (collectmoveinterference(underboard, thepieces, y, x, thepieces[y][x].getcolor())) {
                    std::vector<int> staredownpiece = {y, x, underboard[y][x]};
                    return staredownpiece;
                }
            }
        }
    }
    return {};
}

bool Chess::King::cannotblock(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {
    std::vector<int> piecechecking;
    char piecetype;
    piecechecking = grabstaredown(underboard, thepieces, color);
    std::vector<std::pair<int, int>> dirs = {{startposy - 1, startposx - 1}, {startposy - 1, startposx}, {startposy - 1, startposx + 1}, {startposy, startposx - 1}, {startposy, startposx + 1},
                                             {startposy + 1, startposx - 1}, {startposy + 1, startposx}, {startposy + 1, startposx + 1}};
    for (auto item : dirs) {
        if (item.first >= 0 and item.first < underboard.size()
        and item.second >= 0 and item.second < underboard[0].size())
        {
            if (currstarekingy != -9000 and currstarekingx != -9000 and
            currstarekingy == item.first and currstarekingx == item.second)
            {
                for (int y = 0; y < underboard.size(); y++)
                {
                    for (int x = 0; x < underboard[0].size(); x++)
                    {
                        if (thepieces[y][x].getcolor() == color and underboard[y][x] != ' ' and underboard[y][x] != 'A')
                        {
                            collectmoveinterference2(underboard, thepieces, y, x, thepieces[y][x].getcolor());
                        }
                    }
                }
                for (auto intmoves : interferemoves2)
                {
                    if (intmoves.first == currstarekingy and intmoves.second == currstarekingx)
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}


bool Chess::King::determinecheckmate(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {
    GenerateMoves(underboard, thepieces, color);
    if (determinecheck(underboard, thepieces, color) and possiblemoves.size() == 0)
    {
        return true;
    } else
    {
        return false;
    }

}

void Chess::King::clearpossiblemoves() {
    possiblemoves = {};
}
