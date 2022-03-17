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
    //king cannot eat protected pieces;
    std::cout << "King Generation!" << std::endl;
    std::string kingcolor = color;
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
        and (underboard[item.first][item.second] == ' ' or (underboard[item.first][item.second] != ' ' and thepieces[item.first][item.second].getcolor() != color
        and !IsPieceProtected(item.first, item.second))))
        {
            std::cout << "current possible move: " << "rowy " << item.first << "rowx " << item.second << std::endl;
            possiblemoves.emplace_back(item);
        }
        if (InBounds(item.first, item.second, underboard) and underboard[item.first][item.second] != ' '
        and thepieces[item.first][item.second].getcolor() == color)
        {
            protectingsquares.emplace_back(item);
        }
    }
    /*
 *  when it comes to checkmates, there are multiple cases
 *  checkmated cause u cannot move anywhere, cannot block,
 *  also if the piece that is within your range is protected (i.e. king cannot eat it and another piece cannot gobble it )
 *
 */

    if (kingcolor == "white")
    {
        kingcolor = "black";
    } else
    {
        kingcolor = "white";
    }
    std::pair<int, int> oppking = findking(kingcolor, underboard, thepieces);
    std::vector<std::pair<int,int>> kingoverlapmoves = grabopposingkingssquares(underboard, thepieces, oppking.first, oppking.second, color);
    for (auto items : kingoverlapmoves)
    {
        std::vector<std::pair<int,int>>::iterator it;
        it = std::find(possiblemoves.begin(), possiblemoves.end(), items);
        if (it != possiblemoves.end())
        {
            possiblemoves.erase(it);
        }
    }
}



bool Chess::King::cangobblenearking(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {
    // collectmoveinterference2(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, int y, int x, std::string color, std::vector<std::pair<int, int>>& addedmoves)
    std::vector<std::pair<int, int>> ourmoves;
    std::vector<std::pair<int, int>> checkmoves;
    std::pair<int,int> currcheckmove;
    std::vector<std::pair<char, std::vector<std::pair<int, int>>>> currmvavailable;
    std::vector<std::pair<int, int>> piecestartingpos;
    std::vector<std::vector<char>> tempunderboard = underboard;
    std::vector<std::vector<Pieces>> temppieces = thepieces;
    int pieceitr = 0;
    for (int y = 0; y < underboard.size(); y++)
    {
        for (int x = 0; x < underboard[0].size(); x++)
        {
            if (thepieces[y][x].getcolor() == color and underboard[y][x] != ' ')
            {
               currcheckmove = collectmoveinterference2(underboard, thepieces, y, x, thepieces[y][x].getcolor(),ourmoves, currmvavailable);
               int row = y;
               int col = x;
               piecestartingpos.push_back({y, x});
            }
        }
    }

    for (auto movechars : currmvavailable)
    {
        for (std::pair<int, int> moves : movechars.second) {
            if (moves.first == piecechecky and moves.second == piececheckx)
            {
                char oldpiece = movechars.first;
                underboard[piecestartingpos[pieceitr].first][piecestartingpos[pieceitr].second] = ' ';
                underboard[moves.first][moves.second] = oldpiece;
                thepieces[moves.first][moves.second] = thepieces[piecestartingpos[pieceitr].first][piecestartingpos[pieceitr].second];
                thepieces[piecestartingpos[pieceitr].first][piecestartingpos[pieceitr].second].settype(' ');
                thepieces[piecestartingpos[pieceitr].first][piecestartingpos[pieceitr].second].setblank(true);
                thepieces[piecestartingpos[pieceitr].first][piecestartingpos[pieceitr].second].setcolor("");
                if (!determinecheck(underboard, thepieces, color)) {
                    underboard = tempunderboard;
                    thepieces = temppieces;
                    return true;
                }
                underboard = tempunderboard;
                thepieces = temppieces;
            }
        }
        pieceitr += 1;
    }
    underboard = tempunderboard;
    thepieces = temppieces;
    std::cout << "Cannot gobble near king" << std::endl;
    return false;
}


bool Chess::King::IsPieceProtected(int opppiecerowpos, int opppiececolpos) {
    for (auto protectedsq : totalprotectingsquares)
    {
        if (opppiecerowpos == protectedsq.first and opppiececolpos == protectedsq.second)
        {
            return true;
        }
    }
    return false;
}

std::pair<int, int> Chess::King::findking(std::string color, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces) {
    for (int height = 0; height < 8; height++)
    {
        for (int width = 0; width < 8; width++)
        {
            if (underboard[height][width] == 'A' and thepieces[height][width].getcolor() == color)
            {
                std::pair<int, int> kingcoords = std::make_pair(height,width);
                return kingcoords;
            }
        }
    }
    return {};
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



bool Chess::King::CastleCheckGeneration(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::vector<std::pair<int,int>> possiblemoves,  std::string color) {
    std::vector<std::pair<int, int>> wqsidecoords = {{startposy, startposx - 1}, {startposy, startposx - 2}, {startposy, startposx - 3}};
    std::vector<std::pair<int, int>> wkingsidecoords = {{startposy, startposx + 1}, {startposy, startposx + 2}};
    std::vector<std::pair<int, int>> bqsidecoords;
    std::vector<std::pair<int, int>> bkingsidecoords;
    bool qsidehrook = false;
    bool ksinghrook = false;
    bool qsideclear = true;
    bool ksideclear = true;
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
    int currentendposxleft = startposx - 2;
    if (!qsidehrook)
    {
            return false;
    }
    for (int xbet = startposx - 1; xbet >= 1; xbet--) {
        if (underboard[startposy][xbet] != ' ') {
            return false;
        }
    }


    int currentendposright = startposx + 2;
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
            for (std::pair<int, int> item : wqsidecoords)
            {
                if (move == item)
                {
                    qsideclear = false;
                }
            }
            for (std::pair<int, int> item : wkingsidecoords)
            {
                if (move == item)
                {
                    ksideclear = false;
                }
            }
        }
    if (qsideclear)
    {
        possiblemoves.emplace_back(std::make_pair(startposy, currentendposxleft));
    }
    if (ksideclear) {
        possiblemoves.emplace_back(std::make_pair(startposy, currentendposright));
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
    bool staredowntrue = false;
    switch (underboard[y][x])
    {
        case 'P':
            pawnobj.GenerateMoves(underboard, thepieces, color);
            if (pawnobj.getstaredown())
            {
                std::cout << "Pawn stare down" << std::endl;
                staredowntrue = true;
                piecechecky = y;
                piececheckx = x;
            }
            this->addmoves(pawnobj.getwatchingsquares(), interferemoves);
            this->addmoves(pawnobj.protectingsquares, totalprotectingsquares);
            break;
        case 'R':
            rookobj.GenerateMoves(underboard, thepieces, color);
            if (rookobj.getstaredown())
            {
                currstarekingy = rookobj.getstaredownkingy();
                currstarekingx = rookobj.getstaredownkingx();
                std::cout << "Rook stare down" << std::endl;
                piecechecky = y;
                piececheckx = x;
                staredowntrue = true;
            }
            this->addmoves(rookobj.getpossiblemoves(), interferemoves);
            this->addmoves(rookobj.protectingsquares, totalprotectingsquares);
            break;
        case 'B':
            bishopobj.GenerateMoves(underboard, thepieces, color);
            if (bishopobj.getstaredown())
            {
                currstarekingy = bishopobj.getstaredownkingy();
                currstarekingx = bishopobj.getstaredownkingx();
                std::cout << "bishop stare down" << std::endl;
                piecechecky = y;
                piececheckx = x;
                staredowntrue = true;
            }
            this->addmoves(bishopobj.getpossiblemoves(), interferemoves);
            this->addmoves(bishopobj.protectingsquares, totalprotectingsquares);
            break;
        case 'Q':
            queenobj.GenerateMoves(underboard, thepieces, color);
            if (queenobj.getstaredown())
            {
                currstarekingy = queenobj.getstaredownkingy();
                currstarekingx = queenobj.getstaredownkingx();
                piecechecky = y;
                piececheckx = x;
                staredowntrue = true;
            }
            this->addmoves(queenobj.getpossiblemoves(), interferemoves);
            this->addmoves(queenobj.protectingsquares, totalprotectingsquares);
            break;
        case 'K':
            knightobj.GenerateMoves(underboard, thepieces, color);
            if (knightobj.getstaredown())
            {
                std::cout << "knight stare down" << std::endl;
                piecechecky = y;
                piececheckx = x;
                staredowntrue = true;
            }
            this->addmoves(knightobj.getpossiblemoves(), interferemoves);
            this->addmoves(knightobj.protectingsquares, totalprotectingsquares);
            break;
        default:
            break;
    }
    if (staredowntrue)
    {
        return true;
    }
    return false;
}


//pair<char, vector<pair<int, int>>
std::pair<int, int> Chess::King::collectmoveinterference2(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, int y, int x, std::string color, std::vector<std::pair<int, int>>& addedmoves, std::vector<std::pair<char, std::vector<std::pair<int, int>>>>& currmvavailable) {
    Pawn pawnobj(x, y, -9000, -9000);
    Rook rookobj(x, y, -9000, -9000);
    Queen queenobj(x, y, -9000, -9000);
    Bishop bishopobj(x, y, -9000, -9000);
    King kingobj(x, y, -9000, -9000);
    Knight knightobj(x, y, -9000, -9000);
    std::vector<std::pair<int, int>> newmoves;
    std::pair<int, int> checkpiecepos = {-9000, -9000};
    switch (underboard[y][x])
    {
        case 'P':
            pawnobj.GenerateMoves(underboard, thepieces, color);
            newmoves = pawnobj.getpossiblemoves();
            if (pawnobj.getstaredown())
            {
                checkpiecepos = {y, x};
            }
            currmvavailable.push_back({'P', newmoves});
            break;
        case 'R':
            rookobj.GenerateMoves(underboard, thepieces, color);
            this->addmoves(rookobj.getpossiblemoves(), addedmoves);
            newmoves =  rookobj.getpossiblemoves();
            if (rookobj.getstaredown())
            {
                checkpiecepos = {y, x};
            }
            currmvavailable.push_back({'R', newmoves});
            break;
        case 'B':
            bishopobj.GenerateMoves(underboard, thepieces, color);
            this->addmoves(bishopobj.getpossiblemoves(), addedmoves);
            newmoves = bishopobj.getpossiblemoves();
            if (bishopobj.getstaredown())
            {
                checkpiecepos = {y, x};
            }
            currmvavailable.push_back(std::make_pair('B', newmoves));
            break;
        case 'Q':
            queenobj.GenerateMoves(underboard, thepieces, color);
            this->addmoves(queenobj.getpossiblemoves(), addedmoves);
            newmoves = queenobj.getpossiblemoves();
            if (queenobj.getstaredown())
            {
                checkpiecepos = {y, x};
            }
            currmvavailable.push_back(std::make_pair('Q', newmoves));
            break;
        case 'K':
            knightobj.GenerateMoves(underboard, thepieces, color);
            this->addmoves(knightobj.getpossiblemoves(),  addedmoves);
            newmoves = knightobj.getpossiblemoves();
            if (knightobj.getstaredown()) {
                checkpiecepos = {y, x};
            }
            currmvavailable.push_back(std::make_pair('K', newmoves));
            break;
        default:
            break;
    }
    return checkpiecepos;
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


std::vector<std::pair<int,int>> Chess::King::grabopposingkingssquares(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, int y, int x, std::string color) {
    std::vector<std::pair<int, int>> dirs = {{startposy - 1, startposx - 1}, {startposy - 1, startposx}, {startposy - 1, startposx + 1}, {startposy, startposx - 1}, {startposy, startposx + 1},
                                             {startposy + 1, startposx - 1}, {startposy + 1, startposx}, {startposy + 1, startposx + 1}};
    std::vector<std::pair<int, int>> opponentdirs = {{y - 1, x - 1}, {y - 1, x}, {y - 1, x + 1}, {y, x - 1}, {y, x+ 1},
                                                {y + 1, x- 1}, {y + 1, x}, {y + 1, x + 1}};
    std::vector<std::pair<int,int>> overlappingmoves;
    for (auto ourking : dirs) {
        for (auto opponentking: opponentdirs) {
            if (InBounds(ourking.first, ourking.second, underboard) and
                InBounds(opponentking.first, opponentking.second, underboard) and ourking == opponentking) {
                overlappingmoves.push_back({ourking.first, ourking.second});
            }
        }
    }
    return overlappingmoves;
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

/*
 *  when it comes to checkmates, there are multiple cases
 *  checkmated cause u cannot move anywhere, cannot block,
 *  also if the piece that is within your range is protected (i.e. king cannot eat it and another piece cannot gobble it )
 *
 */
bool Chess::King::cannotblock(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {
    std::vector<int> piecechecking;
    char piecetype;
    piecechecking = grabstaredown(underboard, thepieces, color);
    std::vector<std::pair<int, int>> dirs = {{startposy - 1, startposx - 1}, {startposy - 1, startposx}, {startposy - 1, startposx + 1}, {startposy, startposx - 1}, {startposy, startposx + 1},
                                             {startposy + 1, startposx - 1}, {startposy + 1, startposx}, {startposy + 1, startposx + 1}};
    //deal with protected pieces here;
    //have to deal with when the piece that is checking is in the range of the king
    //from one of the directions
    //if the piece is in the range (standing on one of the king's 8 tiles)
    /*
     * Need to rechange this whole entire function
     * I need every possible move from myself and check if I have available moves that can block the current onslaught
     * test each move and see if im still in check to see if it blocks the piece that is checking me
     * first, save a copy of underboard.
     * you can also block from afar, and this new function takes care of that
     * once making the move and you find a move that blocks, then we can return false
     */

    if (piecechecking.size() == 0)
    {
        return false;
    }
    std::cout << "Seg fault here?" << std::endl;
    std::vector<std::pair<int, int>> piecestartingpos;
    std::vector<std::vector<char>> tempunderboard = underboard;
    std::vector<std::vector<Pieces>> temppieces = thepieces;
    std::vector<std::pair<char, std::vector<std::pair<int, int>>>> currmvavailable;
    for (int y = 0; y < underboard.size(); y++)
    {
        for (int x = 0; x < underboard[0].size(); x++)
        {
            if (thepieces[y][x].getcolor() == color and underboard[y][x] != ' ' and underboard[y][x] != 'A')
            {
                collectmoveinterference2(underboard, thepieces, y, x, thepieces[y][x].getcolor(), interferemoves2, currmvavailable);
                int rowval = y;
                int colval = x;
                piecestartingpos.emplace_back(std::make_pair(rowval, colval));
            }
        }
    }
    int currstartcoords = 0;
    for (auto item : currmvavailable)
    {
        std::cout << "get past currmavaiable" << std::endl;
        for (std::pair<int, int> currmove : item.second)
        {
            char oldpiece = item.first;
            underboard[piecestartingpos[currstartcoords].first][piecestartingpos[currstartcoords].second] = ' ';
            underboard[currmove.first][currmove.second] = oldpiece;
            thepieces[currmove.first][currmove.second] = thepieces[piecestartingpos[currstartcoords].first][piecestartingpos[currstartcoords].second];
            thepieces[piecestartingpos[currstartcoords].first][piecestartingpos[currstartcoords].second].settype(' ');
            thepieces[piecestartingpos[currstartcoords].first][piecestartingpos[currstartcoords].second].setblank(true);
            thepieces[piecestartingpos[currstartcoords].first][piecestartingpos[currstartcoords].second].setcolor("");
            if (!determinecheck(underboard, thepieces, color))
            {
                underboard = tempunderboard;
                thepieces = temppieces;
                std::cout << "Made it past cannotblock" << std::endl;
                interferemoves2 = {};
                return false;
            }
            underboard = tempunderboard;
            thepieces = temppieces;
        }
        currstartcoords += 1;
    }
    underboard = tempunderboard;
    thepieces = temppieces;
    interferemoves2 = {};

    return true;
}


bool Chess::King::determinecheckmate(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {
    GenerateMoves(underboard, thepieces, color);
    for (auto item : possiblemoves)
    {
        std::cout << "Move coordinates: " << item.first << " " << item.second;
    }
    if (possiblemoves.size() == 0) {
        std::cout << "No moves available!" << std::endl;
    }
    if (determinecheck(underboard, thepieces, color) and possiblemoves.size() == 0
    and cannotblock(underboard, thepieces, color) and !cangobblenearking(underboard, thepieces, color))
    {
        std::cout << "checkmate determined?" << std::endl;
        return true;
    } else
    {
        return false;
    }

}

void Chess::King::clearpossiblemoves() {
    possiblemoves = {};
}


void Chess::King::setstartpos(int startposy, int startposx) {
    this->startposy = startposy;
    this->startposx = startposx;
}


/*
   for (auto item : dirs)
   {
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
                           collectmoveinterference2(underboard, thepieces, y, x, thepieces[y][x].getcolor(), interferemoves2);
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
    */
