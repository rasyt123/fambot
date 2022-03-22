//
// Created by rasyt on 12/21/2021.
//

#include "MediumAi.h"



void Chess::MediumAi::whitesetPawnevalsquares() {
    pawnevalsquares = {{0,  0,  0,  0,  0,  0,  0,  0},
                       {50, 50, 50, 50, 50, 50, 50, 50},
                       {10, 10, 20, 30, 30, 20, 10, 10},
                       {5,  5, 10, 25, 25, 10,  5,  5},
                       {0,  0,  0, 20, 20,  0,  0,  0},
                       {5, -5,-10,  0,  0,-10, -5,  5},
                       {5, 10, 10,-20,-20, 10, 10,  5},
                       {0,  0,  0,  0,  0,  0,  0,  0}};
};



void Chess::MediumAi::whitesetKnightevalsquares() {
    knightevalsquares = {{-50,-40,-30,-30,-30,-30,-40,-50},
                         {-40,-20,  0,  0,  0,  0,-20,-40},
                         {-30,  0, 10, 15, 15, 10,  0,-30},
                         {-30,  5, 15, 20, 20, 15,  5,-30},
                         {-30,  0, 15, 20, 20, 15,  0,-30},
                         {-30,  5, 10, 15, 15, 10,  5,-30},
                         {-40,-20,  0,  5,  5,  0,-20,-40},
                         {-50,-40,-30,-30,-30,-30,-40,-50}};
}


void Chess::MediumAi::whitesetBishopevalsquares() {
    bishopevalsquares = {{-20,-10,-10,-10,-10,-10,-10,-20},
                         {-10,  0,  0,  0,  0,  0,  0,-10},
                         {-10,  0,  5, 10, 10,  5,  0,-10},
                         {-10,  5,  5, 10, 10,  5,  5,-10},
                         {-10,  0, 10, 10, 10, 10,  0,-10},
                         {-10, 10, 10, 10, 10, 10, 10,-10},
                         {-10,  5,  0,  0,  0,  0,  5,-10},
                         {-20,-10,-10,-10,-10,-10,-10,-20}};
}



void Chess::MediumAi::whitesetRookevalsquares() {
    rookevalsquares = {{0,  0,  0,  0,  0,  0,  0,  0},
                       {5, 10, 10, 10, 10, 10, 10,  5},
                       {-5,  0,  0,  0,  0,  0,  0, -5},
                       {-5,  0,  0,  0,  0,  0,  0, -5},
                       {-5,  0,  0,  0,  0,  0,  0, -5},
                       {-5,  0,  0,  0,  0,  0,  0, -5},
                       {-5,  0,  0,  0,  0,  0,  0, -5},
                       {0,  0,  0,  5,  5,  0,  0,  0}};
}


void Chess::MediumAi::whitesetQueenevalsquares() {
    queenevalsquares = {{-20,-10,-10, -5, -5,-10,-10,-20},
            {-10,  0,  0,  0,  0,  0,  0,-10},
            {-10,  0,  5,  5,  5,  5,  0,-10},
            {-5,  0,  5,  5,  5,  5,  0, -5},
            {0,  0,  5,  5,  5,  5,  0, -5},
            {-10,  5,  5,  5,  5,  5,  0,-10},
            {-10,  0,  5,  0,  0,  0,  0,-10},
            {-20,-10,-10, -5, -5,-10,-10,-20}};
}


void Chess::MediumAi::whitesetKingevalsquares() {
    kingevalsquares = {{-50,-40,-30,-20,-20,-30,-40,-50},
                       {-30,-20,-10,  0,  0,-10,-20,-30},
                       {-30,-10, 20, 30, 30, 20,-10,-30},
                       {-30,-10, 30, 40, 40, 30,-10,-30},
                       {-30,-10, 30, 40, 40, 30,-10,-30},
                       {-30,-10, 20, 30, 30, 20,-10,-30},
                       {-30,-30,  0,  0,  0,  0,-30,-30},
                       {-50,-30,-30,-30,-30,-30,-30,-50}};
}


void Chess::MediumAi::endgamewhitesetkingevalsquares() {
    endgamekingevalsquares =
            {{-50,-40,-30,-20,-20,-30,-40,-50},
             {-30,-20,-10,  0,  0,-10,-20,-30},
             {-30,-10, 20, 30, 30, 20,-10,-30},
             {-30,-10, 30, 40, 40, 30,-10,-30},
             {-30,-10, 30, 40, 40, 30,-10,-30},
             {-30,-10, 20, 30, 30, 20,-10,-30},
             {-30,-30,  0,  0,  0,  0,-30,-30},
             {-50,-30,-30,-30,-30,-30,-30,-50}};
}


void Chess::MediumAi::endgameblacksetkingevalsquares() {
    std::vector<std::vector<int>> temp = endgamekingevalsquares;
    std::reverse(temp.begin(), temp.end());
    blackendgamekingevalsquares = endgamekingevalsquares;
}




void Chess::MediumAi::blacksetPawnevalsquares() {
    std::vector<std::vector<int>> temp = pawnevalsquares;
    std::reverse(temp.begin(), temp.end());
    blackpawnevalsquares = temp;
}


void Chess::MediumAi::blacksetKnightevalsquares() {
    std::vector<std::vector<int>> temp = knightevalsquares;
    std::reverse(temp.begin(), temp.end());
    blackknightevalsquares = temp;
}


void Chess::MediumAi::blacksetBishopevalsquares() {
    std::vector<std::vector<int>> temp = bishopevalsquares;
    std::reverse(temp.begin(), temp.end());
    blackbishopevalsquares = temp;
}


void Chess::MediumAi::blacksetRookevalsquares() {
    std::vector<std::vector<int>> temp = rookevalsquares;
    std::reverse(temp.begin(), temp.end());
    blackrookevalsquares = temp;
}


void Chess::MediumAi::blacksetQueenevalsquares() {
    std::vector<std::vector<int>> temp = queenevalsquares;
    std::reverse(temp.begin(), temp.end());
    blackqueenevalsquares = temp;
}


void Chess::MediumAi::blacksetKingevalsquares() {
    std::vector<std::vector<int>> temp = kingevalsquares;
    std::reverse(temp.begin(), temp.end());
    blackkingevalsquares = temp;
}

/*
 * Will include opening and end game phases
 * Dont need to detect draws at the moment
 * Things to add:
 * quiscience search
 * Basic knowledge of pawn structure - doubled, isolated, backward and passed pawns
Something resembling king safety - pawn shield and king tropism results scaled against the strength of opponent's remaining pieces
basic knowledge about endgames drawn by insufficient material
 *
 */

int Chess::MediumAi::staticeval(std::vector<std::vector<char>> underboard, std::vector<std::vector<Pieces>> thepieces, std::string color) {
    int P = 100;
    int N = 320;
    int B = 330;
    int R = 500;
    int Q = 900;
    int K = 20000;
    int totalscore = 0;
    int wscore = 0;
    int bscore = 0;




}

int Chess::MediumAi::countdoubledpawnscore(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {
    int numdoubled = 0;
    for (int i = 0; i < underboard.size(); i++)
    {
        for (int j = 0; j < underboard[0].size(); j++)
        {
            if (underboard[i][j] == 'P' and thepieces[i][j].getcolor() == color
            and i - 1 >= 0 and underboard[i - 1][j] == 'P' and thepieces[i-1][j].getcolor() == color) {
                numdoubled += 1;
            }
        }
    }
    int score = numdoubled * -5;
    return score;
}





int Chess::MediumAi::countisolatedpawnscore(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {
    int numisolated = 0;
    bool hasisolatedleftfile = true;
    bool hasisolatedrightfile = true;
    for (int i = 0; i < underboard.size(); i++)
    {
        for (int j = 0; j < underboard[0].size(); j++)
        {
            if (underboard[i][j] == 'P' and thepieces[i][j].getcolor() == color
                and j - 1 >= 0 and j - 1 <= underboard[0].size() - 1)
            {
                for (int z = 0; z < underboard.size(); z++)
                {
                    if ((underboard[i][j - 1 + z] == 'P' and thepieces[i][j - 1 + z].getcolor() == color)
                    or (underboard[i][j - 1 - z] == 'P' and thepieces[i][j - 1 - z].getcolor() == color))
                    {
                        hasisolatedleftfile = false;
                    }
                }
            }
            if (underboard[i][j] == 'P' and thepieces[i][j].getcolor() == color
                and j + 1 < underboard[0].size())
            {
                for (int z = 0; z < underboard.size(); z++)
                {
                    if ((underboard[i][j + 1 + z] == 'P' and thepieces[i][j + 1 + z].getcolor() == color)
                        or (underboard[i][j + 1 - z] == 'P' and thepieces[i][j + 1 - z].getcolor() == color))
                    {
                        hasisolatedrightfile = false;
                    }
                }

            }
            if (!hasisolatedleftfile and !hasisolatedrightfile)
            {
                numisolated += 1;
            }
            hasisolatedrightfile = true;
            hasisolatedleftfile = true;
        }
    }
    int score = numisolated * -10;
    return score;
}


bool Chess::MediumAi::isWatching(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color, int row, int col) {
    King watching(0, 0, -9000, 9000);
    for (int i = 0; i < underboard.size(); i++)
    {
        for (int j = 0; j < underboard[0].size(); j++)
        {
            if (underboard[i][j] == ' ' and thepieces[i][j].getcolor() != color)
            {
                watching.collectmoveinterference(underboard, thepieces, i, j, color);
            }
        }
    }
    for (auto item : watching.getinterferemoves())
    {
        if (item.first == row and item.second == col)
        {
            return true;
        }
    }
    return false;
}


bool Chess::MediumAi::inbounds(int row, int col) {
    return (row >=0 and row < 8) and (col >=0 and col <8);
}



int Chess::MediumAi::countbackwardpawn(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color, Game& thegame) {
    int numbackwardpawns = 0;
    if (color == "white")
    {
        King watchingpawn(0, 0, -9000, 9000);
        for (int i = 0; i < underboard.size(); i++)
        {
            for (int j = 0; j < underboard[0].size(); j++)
            {
                if (underboard[i][j] == 'P' and thepieces[i][j].getcolor() == "white"
                and ((inbounds(i-1, j-1) and underboard[i-1][j-1] == 'P' and thepieces[i-1][j-1].getcolor() == "white") or (inbounds(i-1, j+1) and underboard[i-1][j+1] == 'P'
                and thepieces[i-1][j+1].getcolor() == "white")))
                {
                    if (underboard[i-1][j] == ' ' and isWatching(underboard, thepieces, color, i -1, j))
                    {
                        numbackwardpawns += 1;
                    }
                }
            }
        }
    } else if (color == "black")
    {
        King watchingpawn(0, 0, -9000, 9000);
        for (int i = 0; i < underboard.size(); i++)
        {
            for (int j = 0; j < underboard[0].size(); j++)
            {
                if (underboard[i][j] == 'P' and thepieces[i][j].getcolor() == "black"
                    and ((inbounds(i + 1, j - 1) and underboard[i+1][j-1] == 'P' and thepieces[i+1][j-1].getcolor() == "black") or (inbounds(i+1, j+1) and
                    underboard[i+1][j+1] == 'P' and thepieces[i+1][j+1].getcolor() == "black")))
                {
                    if (underboard[i+1][j] == ' ' and isWatching(underboard, thepieces, color, i+1, j))
                    {
                        numbackwardpawns += 1;
                    }
                }
            }
        }
    }
    return -4 * numbackwardpawns;
}

int Chess::MediumAi::countpassedpawn(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color) {
        int numpassedpawns = 0;
        bool ispassed = true;
        for (int i = 0; i < underboard.size(); i++)
        {
            for (int j = 0; j < underboard[0].size(); j++)
            {
                if (color == "white" and underboard[i][j] == 'P' and thepieces[i][j].getcolor() == "white")
                {
                    for (int z = 0; z < underboard.size() and ispassed; z++)
                    {
                        if ((inbounds(i-1-z, j-1) and underboard[i-1-z][j-1] == 'P'
                        and thepieces[i-1-z][j-1].getcolor() == "black") or (
                                (inbounds(i-1-z, j) and underboard[i-1-z][j] == 'P' and thepieces[i-1-z][j].getcolor() == "black")
                                or (inbounds(i-1-z, j+1) and underboard[i-1-z][j+1] == 'P' and thepieces[i-1-z][j+1].getcolor() == "black")))
                        {
                            ispassed = false;
                        }
                    }
                } else if (color == "black" and underboard[i][j] == 'P' and thepieces[i][j].getcolor() == "black")
                {
                    for (int z = 0; z < underboard.size() and ispassed; z++)
                    {
                        if ((inbounds(i+1+z, j-1) and underboard[i+1+z][j-1] == 'P'
                             and thepieces[i+1+z][j-1].getcolor() == "white") or (
                                    (inbounds(i+1+z, j) and underboard[i+1+z][j] == 'P' and thepieces[i+1+z][j].getcolor() == "white")
                                    or (inbounds(i+1+z, j+1) and underboard[i+1+z][j+1] == 'P' and thepieces[i+1+z][j+1].getcolor() == "white")))
                        {
                            ispassed = false;
                        }
                    }
                }
                if (ispassed)
                {
                    numpassedpawns += 1;
                    ispassed = false;
                }
            }
        }
        return 8 * numpassedpawns;
}


int Chess::MediumAi::minimaxalphabeta(std::vector<std::vector<char>> underboard, std::vector<std::vector<Pieces>> thepieces, int depth, int alpha, int beta, std::string maximizingPlayer, Game& thegame){
    //bool Chess::Game::checkmate(std::string colorturn, int endposy, int endposx) {
    //-10, -11, -12 will be values for
    if (depth == 0 or thegame.checkmate(maximizingPlayer, -9000, 9000))
    {
        return staticeval(underboard, thepieces, maximizingPlayer);
    }
    if (maximizingPlayer == "white")
    {
        int maxEvaluation = -INT_MAX;
        //check if im currently able to castle on both ways and add that move in

        //std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::vector<std::pair<int,int>> possiblemoves,  std::string color
        std::vector<std::pair<char, std::vector<int>>> possiblemoves = getallpossiblemoves(maximizingPlayer, underboard, thepieces);
        //getallpossiblemoves will handle move types like enpassant, promotion

        //castle move additions
        King jking(0, 0, -9000, -9000);
        std::pair<int, int> ourking = jking.findking(maximizingPlayer, underboard, thepieces);
        std::vector<std::pair<int,int>> currcheckmoves;
        jking.setstartpos(ourking.first, ourking.second);
        jking.CastleCheckGeneration(underboard, thepieces, currcheckmoves, maximizingPlayer);
        for (auto item: currcheckmoves)
        {
            std::vector<int> currmove = {item.first, item.second, CASTLE};
            std::pair<char, std::vector<int>> castlepairs = std::make_pair('A', currmove);
            possiblemoves.emplace_back(castlepairs);
        }
        Player matter;
        for (std::pair<char, std::vector<int>>& move : possiblemoves)
        {
            std::vector<std::vector<char>> prevboard = underboard;
            std::vector<std::vector<Pieces>> prevpieces = thepieces;
            if (move.second.size() == 5 and move.second[4] == CASTLE)
            {
                King tempking(move.second[1], move.second[0], move.second[3], move.second[2]);
                tempking.CastleMovement(underboard, thepieces);
            } else 
            {
                thegame.move(underboard, thepieces, maximizingPlayer, move.second[0], move.second[1], move.second[2], move.second[3], matter);
            }
            if (move.first == 'P' and move.second[2] == 0)
            {
                updatepiece(underboard, thepieces, move.second[3], move.second[4], 'Q');
            }
            int eval = minimaxalphabeta(underboard, thepieces, depth - 1, alpha, beta, maximizingPlayer, thegame);
            underboard = prevboard;
            thepieces = prevpieces;
            maxEvaluation = std::max(maxEvaluation, eval);
            alpha = std::max(alpha, eval);
            if (beta <= alpha)
            {
                break;
            }
        }
        return maxEvaluation;

    } else
    {
        int minEvaluation = INT_MAX;
        std::vector<std::pair<char, std::vector<int>>> possiblemoves = getallpossiblemoves(maximizingPlayer, underboard, thepieces);
        //getallpossiblemoves will handle move types like enpassant, promotion
        King jking(0, 0, -9000, -9000);
        std::pair<int, int> ourking = jking.findking(maximizingPlayer, underboard, thepieces);
        std::vector<std::pair<int,int>> currcheckmoves;
        jking.setstartpos(ourking.first, ourking.second);
        jking.CastleCheckGeneration(underboard, thepieces, currcheckmoves, maximizingPlayer);
        for (auto item: currcheckmoves)
        {
            std::vector<int> currmove = {item.first, item.second};
            std::pair<char, std::vector<int>> castlepairs = std::make_pair('A', currmove);
            possiblemoves.emplace_back(castlepairs);
        }
        Player matter;
        for (std::pair<char, std::vector<int>>& move : possiblemoves)
        {
            std::vector<std::vector<char>> prevboard = underboard;
            std::vector<std::vector<Pieces>> prevpieces = thepieces;
            if (move.second.size() == 5 and move.second[4] == CASTLE)
            {
                King tempking(move.second[1], move.second[0], move.second[3], move.second[2]);
                tempking.CastleMovement(underboard, thepieces);
            } else
            {
                thegame.move(underboard, thepieces, maximizingPlayer, move.second[0], move.second[1], move.second[2], move.second[3], matter);
            }
            if (move.first == 'P' and move.second[2] == 7)
            {
                updatepiece(underboard, thepieces, move.second[3], move.second[4], 'Q');
            }
            int eval = minimaxalphabeta(underboard, thepieces, depth - 1, alpha, beta, maximizingPlayer, thegame);
            underboard = prevboard;
            thepieces = prevpieces;
            minEvaluation = std::min(minEvaluation, eval);
            beta = std::min(beta, eval);
            if (beta <= alpha)
            {
                break;
            }
        }
        return minEvaluation;
    }
}


void Chess::MediumAi::updatepiece(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, int endposrow, int endposcol, char piece) {
    underboard[endposrow][endposcol] = piece;
    thepieces[endposrow][endposcol].settype(piece);
}



std::vector<std::pair<char, std::vector<int>>> Chess::MediumAi::getallpossiblemoves(std::string color, std::vector<std::vector<char>> underboard, std::vector<std::vector<Pieces>> thepieces) {
    std::vector<std::pair<char, std::vector<int>>> allpossiblemoves;
    Pawn pawnobj(0, 0, -9000, -9000);
    Rook rookobj(0, 0, -9000, -9000);
    Knight knightobj(0, 0, -9000, -9000);
    King kingobj(0, 0, -9000, -9000);
    Queen queenobj(0, 0, -9000, -9000);
    Bishop bishopobj(0, 0, -9000, -9000);
    //special moves I need to add:
    //castling, en passant, promotion
        for (int i = 0; i < underboard.size(); i++)
        {
            for (int j = 0; j < underboard[0].size(); i++)
            {
                if (thepieces[i][j].getcolor() == color and underboard[i][j] != ' ')
                {
                    switch (underboard[i][j])
                    {
                        case 'P':
                            pawnobj.setstartpos(i, j);
                            pawnobj.getpossiblemoves();
                            for (auto item : pawnobj.getpossiblemoves())
                            {
                                std::vector<int> moves;
                                moves.push_back(i);
                                moves.push_back(j);
                                moves.push_back(item.first);
                                moves.push_back(item.second);
                                std::pair<char, std::vector<int>> movecomb = std::make_pair(underboard[i][j], moves);
                                allpossiblemoves.push_back(movecomb);
                            }
                            break;
                        case 'R':
                            rookobj.setstartpos(i, j);
                            rookobj.getpossiblemoves();
                            for (auto item : rookobj.getpossiblemoves())
                            {
                                std::vector<int> moves;
                                moves.push_back(i);
                                moves.push_back(j);
                                moves.push_back(item.first);
                                moves.push_back(item.second);
                                std::pair<char, std::vector<int>> movecomb = std::make_pair(underboard[i][j], moves);
                                allpossiblemoves.push_back(movecomb);
                            }

                            break;
                        case 'K':
                            knightobj.setstartpos(i, j);
                            knightobj.getpossiblemoves();
                            for (auto item : knightobj.getpossiblemoves())
                            {
                                std::vector<int> moves;
                                moves.push_back(i);
                                moves.push_back(j);
                                moves.push_back(item.first);
                                moves.push_back(item.second);
                                std::pair<char, std::vector<int>> movecomb = std::make_pair(underboard[i][j], moves);
                                allpossiblemoves.push_back(movecomb);
                            }
                            break;
                        case 'B':
                            bishopobj.setstartpos(i, j);
                            bishopobj.getpossiblemoves();
                            for (auto item : bishopobj.getpossiblemoves())
                            {
                                std::vector<int> moves;
                                moves.push_back(i);
                                moves.push_back(j);
                                moves.push_back(item.first);
                                moves.push_back(item.second);
                                std::pair<char, std::vector<int>> movecomb = std::make_pair(underboard[i][j], moves);
                                allpossiblemoves.push_back(movecomb);
                            }
                            break;
                        case 'Q':
                            queenobj.setstartpos(i, j);
                            queenobj.getpossiblemoves();
                            for (auto item : queenobj.getpossiblemoves())
                            {
                                std::vector<int> moves;
                                moves.push_back(i);
                                moves.push_back(j);
                                moves.push_back(item.first);
                                moves.push_back(item.second);
                                std::pair<char, std::vector<int>> movecomb = std::make_pair(underboard[i][j], moves);
                                allpossiblemoves.push_back(movecomb);
                            }

                            break;
                        case 'A':
                            kingobj.setstartpos(i, j);
                            kingobj.getpossiblemoves();
                            for (auto item : kingobj.getpossiblemoves())
                            {
                                std::vector<int> moves;
                                moves.push_back(i);
                                moves.push_back(j);
                                moves.push_back(item.first);
                                moves.push_back(item.second);
                                std::pair<char, std::vector<int>> movecomb = std::make_pair(underboard[i][j], moves);
                                allpossiblemoves.push_back(movecomb);
                            }
                            break;
                    }
                }
            }
        }
}





