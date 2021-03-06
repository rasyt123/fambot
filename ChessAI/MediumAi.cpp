//
// Created by rasyt on 12/21/2021.
//

#include "MediumAi.h"


void Chess::MediumAi::whitesetPawnevalsquares() {
    pawnevalsquares = {{0,  0,  0,   0,   0,   0,   0,  0},
                       {50, 50, 50,  50,  50,  50,  50, 50},
                       {10, 10, 20,  30,  30,  20,  10, 10},
                       {5,  5,  10,  25,  25,  10,  5,  5},
                       {0,  0,  0,   20,  20,  0,   0,  0},
                       {5,  -5, -10, 0,   0,   -10, -5, 5},
                       {5,  10, 10,  -20, -20, 10,  10, 5},
                       {0,  0,  0,   0,   0,   0,   0,  0}};
};


void Chess::MediumAi::whitesetKnightevalsquares() {
    knightevalsquares = {{-50, -40, -30, -30, -30, -30, -40, -50},
                         {-40, -20, 0,   0,   0,   0,   -20, -40},
                         {-30, 0,   10,  15,  15,  10,  0,   -30},
                         {-30, 5,   15,  20,  20,  15,  5,   -30},
                         {-30, 0,   15,  20,  20,  15,  0,   -30},
                         {-30, 5,   10,  15,  15,  10,  5,   -30},
                         {-40, -20, 0,   5,   5,   0,   -20, -40},
                         {-50, -40, -30, -30, -30, -30, -40, -50}};
}


void Chess::MediumAi::whitesetBishopevalsquares() {
    bishopevalsquares = {{-20, -10, -10, -10, -10, -10, -10, -20},
                         {-10, 0,   0,   0,   0,   0,   0,   -10},
                         {-10, 0,   5,   10,  10,  5,   0,   -10},
                         {-10, 5,   5,   10,  10,  5,   5,   -10},
                         {-10, 0,   10,  10,  10,  10,  0,   -10},
                         {-10, 10,  10,  10,  10,  10,  10,  -10},
                         {-10, 5,   0,   0,   0,   0,   5,   -10},
                         {-20, -10, -10, -10, -10, -10, -10, -20}};
}


void Chess::MediumAi::whitesetRookevalsquares() {
    rookevalsquares = {{0,  0,  0,  0,  0,  0,  0,  0},
                       {5,  10, 10, 10, 10, 10, 10, 5},
                       {-5, 0,  0,  0,  0,  0,  0,  -5},
                       {-5, 0,  0,  0,  0,  0,  0,  -5},
                       {-5, 0,  0,  0,  0,  0,  0,  -5},
                       {-5, 0,  0,  0,  0,  0,  0,  -5},
                       {-5, 0,  0,  0,  0,  0,  0,  -5},
                       {0,  0,  0,  5,  5,  0,  0,  0}};
}


void Chess::MediumAi::whitesetQueenevalsquares() {
    queenevalsquares = {{-20, -10, -10, -5, -5, -10, -10, -20},
                        {-10, 0,   0,   0,  0,  0,   0,   -10},
                        {-10, 0,   5,   5,  5,  5,   0,   -10},
                        {-5,  0,   5,   5,  5,  5,   0,   -5},
                        {0,   0,   5,   5,  5,  5,   0,   -5},
                        {-10, 5,   5,   5,  5,  5,   0,   -10},
                        {-10, 0,   5,   0,  0,  0,   0,   -10},
                        {-20, -10, -10, -5, -5, -10, -10, -20}};
}


void Chess::MediumAi::whitesetKingevalsquares() {
    kingevalsquares = {{-50, -40, -30, -20, -20, -30, -40, -50},
                       {-30, -20, -10, 0,   0,   -10, -20, -30},
                       {-30, -10, 20,  30,  30,  20,  -10, -30},
                       {-30, -10, 30,  40,  40,  30,  -10, -30},
                       {-30, -10, 30,  40,  40,  30,  -10, -30},
                       {-30, -10, 20,  30,  30,  20,  -10, -30},
                       {-30, -30, 0,   0,   0,   0,   -30, -30},
                       {-50, -30, -30, -30, -30, -30, -30, -50}};
}


void Chess::MediumAi::endgamewhitesetkingevalsquares() {
    endgamekingevalsquares =
            {{-50, -40, -30, -20, -20, -30, -40, -50},
             {-30, -20, -10, 0,   0,   -10, -20, -30},
             {-30, -10, 20,  30,  30,  20,  -10, -30},
             {-30, -10, 30,  40,  40,  30,  -10, -30},
             {-30, -10, 30,  40,  40,  30,  -10, -30},
             {-30, -10, 20,  30,  30,  20,  -10, -30},
             {-30, -30, 0,   0,   0,   0,   -30, -30},
             {-50, -30, -30, -30, -30, -30, -30, -50}};
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

int Chess::MediumAi::staticeval(std::vector<std::vector<char>> underboard, std::vector<std::vector<Pieces>> thepieces,
                                std::string color) {
    std::cout << "STATIC EVAL DETECTED" << std::endl;
    int P = 100;
    int N = 320;
    int B = 330;
    int R = 500;
    int Q = 900;
    int K = 20000;
    int totalscore = 0;
    int wmaterialscore = 0;
    int bmaterialscore = 0;
    int wpiecetablescore = 0;
    int bpiecetablescore = 0;
    int wmobilityscore = 0;
    int bmobilityscore = 0;
    int numberofpieces = 0;
    int wkingendgameeval = 0;
    int bkingendgameeval = 0;

    int wkingpiecesquare;
    int wkingy;
    int wkingx;
    int bkingpiecesquare;
    int bkingy;
    int bkingx;
    std::cout << "Underboard size: " << underboard.size();
    for (int i = 0; i < underboard.size(); i++)
    {
        for (int j = 0; j < underboard[0].size(); j++)
        {
            if (underboard[i][j] != ' ' and thepieces[i][j].getcolor() == "white")
            {
                switch (underboard[i][j])
                {
                    case 'P':
                        wmaterialscore += 100;
                        wpiecetablescore += pawnevalsquares[i][j];
                        break;
                    case 'A':
                        wmaterialscore += 20000;
                        wpiecetablescore += kingevalsquares[i][j];
                        wkingendgameeval += endgamekingevalsquares[i][j];
                        wkingpiecesquare = kingevalsquares[i][j];
                        wkingy = i;
                        wkingx = j;
                        break;
                    case 'B':
                        wmaterialscore += 330;
                        wpiecetablescore += bishopevalsquares[i][j];
                        break;
                    case 'R':
                        wmaterialscore += 500;
                        wpiecetablescore += rookevalsquares[i][j];
                        break;
                    case 'Q':
                        wmaterialscore += 900;
                        wpiecetablescore += queenevalsquares[i][j];
                        break;
                    case 'K':
                        wmaterialscore += 320;
                        wpiecetablescore += knightevalsquares[i][j];
                        break;
                }
                numberofpieces += 1;
            } else if (underboard[i][j] != ' ' and thepieces[i][j].getcolor() == "black")
            {
                switch (underboard[i][j])
                {
                    case 'P':
                        bmaterialscore += 100;
                        bpiecetablescore += blackpawnevalsquares[i][j];
                        break;
                    case 'A':
                        bmaterialscore += 20000;
                        bpiecetablescore += blackkingevalsquares[i][j];
                        bkingendgameeval += blackendgamekingevalsquares[i][j];
                        bkingendgameeval = blackkingevalsquares[i][j];
                        bkingy = i;
                        bkingx = j;
                        break;
                    case 'B':
                        bmaterialscore += 330;
                        bpiecetablescore += blackbishopevalsquares[i][j];
                        break;
                    case 'R':
                        bmaterialscore += 500;
                        bpiecetablescore += blackrookevalsquares[i][j];
                        break;
                    case 'Q':
                        bmaterialscore += 900;
                        bpiecetablescore += blackqueenevalsquares[i][j];
                        break;
                    case 'K':
                        bmaterialscore += 320;
                        bpiecetablescore += blackknightevalsquares[i][j];
                        break;
                }
                numberofpieces += 1;
            }
        }
        std::cout << std::endl;
    }

    std::cout << "Past table scores: " << std::endl;
    /*
    int wdpawnpenalty = countdoubledpawnscore(underboard, thepieces, "white");
    int wisopawnpenalty = countisolatedpawnscore(underboard, thepieces, "white");
    int wbpawnpenalty = countbackwardpawn(underboard, thepieces, "white");
    int wpassedpawnbonus = countpassedpawn(underboard, thepieces, "white");
    wmobilityscore = wdpawnpenalty + wisopawnpenalty + wbpawnpenalty + wpassedpawnbonus;


    int bdpawnpenalty = countdoubledpawnscore(underboard, thepieces, "black");
    int bisopawnpenalty = countisolatedpawnscore(underboard, thepieces, "black");
    int bbpawnpenalty = countbackwardpawn(underboard, thepieces, "black");
    int bpassedpawnbonus = countpassedpawn(underboard, thepieces, "black");
    bmobilityscore = bdpawnpenalty + bisopawnpenalty + bbpawnpenalty + bpassedpawnbonus;
    */
    if (numberofpieces <= 12)
    {
        wpiecetablescore = wpiecetablescore - wkingpiecesquare;
        bpiecetablescore = bpiecetablescore - bkingpiecesquare;
        wpiecetablescore += endgamekingevalsquares[wkingy][wkingx];
        bpiecetablescore += blackendgamekingevalsquares[bkingy][bkingx];
    }
    int wtotalscore = wmaterialscore + wpiecetablescore + wmobilityscore;
    int btotalscore = bmaterialscore + bpiecetablescore + bmobilityscore;
    std::cout << "Eval score: " << wtotalscore - btotalscore;
    return wtotalscore - btotalscore;
}


//checked
int Chess::MediumAi::countdoubledpawnscore(std::vector<std::vector<char>> &underboard,
                                           std::vector<std::vector<Pieces>> &thepieces, std::string color) {
    int numdoubled = 0;
    for (int i = 0; i < underboard.size(); i++)
    {
        for (int j = 0; j < underboard[0].size(); j++)
        {
            if (underboard[i][j] == 'P' and thepieces[i][j].getcolor() == color
                and inbounds(i-1, j) and underboard[i - 1][j] == 'P' and thepieces[i - 1][j].getcolor() == color)
            {
                numdoubled += 1;
            }
        }
    }
    int score = numdoubled * -5;
    return score;
}


int Chess::MediumAi::countisolatedpawnscore(std::vector<std::vector<char>> &underboard,
                                            std::vector<std::vector<Pieces>> &thepieces, std::string color) {
    int numisolated = 0;
    bool hasisolatedleftfile = true;
    bool hasisolatedrightfile = true;
    for (int i = 0; i < underboard.size(); i++)
    {
        for (int j = 0; j < underboard[0].size(); j++)
        {
            if (underboard[i][j] == 'P' and thepieces[i][j].getcolor() == color
                and inbounds(i, j - 1))
            {
                for (int z = 0; z < underboard.size(); z++)
                {
                    if ((inbounds(i, j - 1 + z) and underboard[i][j - 1 + z] == 'P' and thepieces[i][j - 1 + z].getcolor() == color)
                        or (inbounds(i,j-1 - z ) and underboard[i][j - 1 - z] == 'P' and thepieces[i][j - 1 - z].getcolor() == color))
                    {
                        hasisolatedleftfile = false;
                    }
                }
            }
            if (underboard[i][j] == 'P' and thepieces[i][j].getcolor() == color
                and inbounds(i, j+1))
            {
                for (int z = 0; z < underboard.size(); z++)
                {
                    if ((inbounds(i, j + 1 + z) and underboard[i][j + 1 + z] == 'P' and thepieces[i][j + 1 + z].getcolor() == color)
                        or (inbounds(i, j+1-z) and underboard[i][j + 1 - z] == 'P' and thepieces[i][j + 1 - z].getcolor() == color))
                    {
                        hasisolatedrightfile = false;
                    }
                }

            }
            if (hasisolatedleftfile and hasisolatedrightfile)
            {
                numisolated += 1;
            }
            hasisolatedleftfile = true;
            hasisolatedrightfile = true;
        }
    }
    int score = numisolated * -10;
    return score;
}


bool Chess::MediumAi::isWatching(std::vector<std::vector<char>> &underboard, std::vector<std::vector<Pieces>> &thepieces,
                            std::string color, int row, int col) {
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
    for (auto item: watching.getinterferemoves())
    {
        if (item.first == row and item.second == col)
        {
            return true;
        }
    }
    return false;
}


bool Chess::MediumAi::inbounds(int row, int col) {
    return (row >= 0 and row < 8) and (col >= 0 and col < 8);
}


int Chess::MediumAi::countbackwardpawn(std::vector<std::vector<char>> &underboard,
                                       std::vector<std::vector<Pieces>> &thepieces, std::string color) {
    int numbackwardpawns = 0;
    if (color == "white")
    {
        King watchingpawn(0, 0, -9000, 9000);
        for (int i = 0; i < underboard.size(); i++)
        {
            for (int j = 0; j < underboard[0].size(); j++)
            {
                if (underboard[i][j] == 'P' and thepieces[i][j].getcolor() == "white"
                    and ((inbounds(i - 1, j - 1) and underboard[i - 1][j - 1] == 'P' and
                          thepieces[i - 1][j - 1].getcolor() == "white") or
                         (inbounds(i - 1, j + 1) and underboard[i - 1][j + 1] == 'P'
                          and thepieces[i - 1][j + 1].getcolor() == "white")))
                {
                    if (inbounds(i-1, j) and underboard[i - 1][j] == ' ' and isWatching(underboard, thepieces, color, i - 1, j))
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
                    and ((inbounds(i + 1, j - 1) and underboard[i + 1][j - 1] == 'P' and
                          thepieces[i + 1][j - 1].getcolor() == "black") or (inbounds(i + 1, j + 1) and
                                                                             underboard[i + 1][j + 1] == 'P' and
                                                                             thepieces[i + 1][j + 1].getcolor() == "black")))
                {
                    if (inbounds(i+1, j) and underboard[i + 1][j] == ' ' and isWatching(underboard, thepieces, color, i + 1, j))
                    {
                        numbackwardpawns += 1;
                    }
                }
            }
        }
    }
    return -4 * numbackwardpawns;
}

int Chess::MediumAi::countpassedpawn(std::vector<std::vector<char>> &underboard,
                                     std::vector<std::vector<Pieces>> &thepieces, std::string color) {
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
                    if ((inbounds(i - 1 - z, j - 1) and underboard[i - 1 - z][j - 1] == 'P'
                         and thepieces[i - 1 - z][j - 1].getcolor() == "black") or (
                                (inbounds(i - 1 - z, j) and underboard[i - 1 - z][j] == 'P' and
                                 thepieces[i - 1 - z][j].getcolor() == "black")
                                or (inbounds(i - 1 - z, j + 1) and underboard[i - 1 - z][j + 1] == 'P' and
                                    thepieces[i - 1 - z][j + 1].getcolor() == "black")))
                    {
                        ispassed = false;
                    }
                }
            } else if (color == "black" and underboard[i][j] == 'P' and thepieces[i][j].getcolor() == "black")
            {
                for (int z = 0; z < underboard.size() and ispassed; z++)
                {
                    if ((inbounds(i + 1 + z, j - 1) and underboard[i + 1 + z][j - 1] == 'P'
                         and thepieces[i + 1 + z][j - 1].getcolor() == "white") or (
                                (inbounds(i + 1 + z, j) and underboard[i + 1 + z][j] == 'P' and
                                 thepieces[i + 1 + z][j].getcolor() == "white")
                                or (inbounds(i + 1 + z, j + 1) and underboard[i + 1 + z][j + 1] == 'P' and
                                    thepieces[i + 1 + z][j + 1].getcolor() == "white")))
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


//Generate the hash of the default position of the pieces beforeand
//make the move, then generate the hash and add it to the set
//I need that hash passed as a parameter to the nodes on the next level
//I do not want to be calculating the hash repeatedly, would be really bad
//for the time complexity
//


int Chess::MediumAi::minimaxalphabeta(std::vector<std::vector<char>> underboard, std::vector<std::vector<Pieces>> thepieces,
                                  int depth, int alpha, int beta, std::string maximizingPlayer, Game &thegame,
                                  unsigned long long int hashvalue, std::pair<char, std::vector<int>> &aichosenmove) {
    //bool Chess::Game::checkmate(std::string colorturn, int endposy, int endposx) {
    //-10, -11, -12 will be values for
    if (depth == 0 or thegame.checkmate(maximizingPlayer, -9000, 9000))
    {
        std::cout << "alpha beta depth max reached" << std::endl;
        return quietsearch(underboard, thepieces, alpha, beta, maximizingPlayer, thegame, 2);
    }
    if (maximizingPlayer == "white")
    {
        std::cout << "Maximizing Player white" << std::endl;
        int maxEvaluation = -INT_MAX;
        //check if im currently able to castle on both ways and add that move in
        //std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::vector<std::pair<int,int>> possiblemoves,  std::string color
        std::vector<std::pair<char, std::vector<int>>> possiblemoves = getallpossiblemoves(maximizingPlayer, underboard,
                                                                                           thepieces, false, thegame);
        //getallpossiblemoves will handle move types like enpassant, promotion
        //castle move additions
        King jking(0, 0, -9000, -9000);
        std::pair<int, int> ourking = jking.findking(maximizingPlayer, underboard, thepieces);
        std::vector<std::pair<int, int>> currcheckmoves;
        jking.setstartpos(ourking.first, ourking.second);
        jking.CastleCheckGeneration(underboard, thepieces, currcheckmoves, maximizingPlayer);
        for (auto item: currcheckmoves)
        {
            std::vector<int> currmove = {ourking.first, ourking.second, item.first, item.second, CASTLE};
            std::pair<char, std::vector<int>> castlepairs = std::make_pair('A', currmove);
            possiblemoves.emplace_back(castlepairs);
        }
        Player matter;
        //for int i = 0; i <
        for (std::pair<char, std::vector<int>> &move: possiblemoves)
        {
            std::vector<std::vector<char>> prevboard = underboard;
            std::vector<std::vector<Pieces>> prevpieces = thepieces;
            if (move.second.size() == 5 and move.second[4] == CASTLE)
            {
                King tempking(move.second[1], move.second[0], move.second[3], move.second[2]);
                tempking.CastleMovement(underboard, thepieces);
            } else
            {
                thegame.move(underboard, thepieces, maximizingPlayer, move.second[0], move.second[1], move.second[2],
                             move.second[3], matter);
            }

            if (move.first == 'P' and move.second[2] == 0)
            {
                updatepiece(underboard, thepieces, move.second[3], move.second[4], 'Q');
            }
            int eval = minimaxalphabeta(underboard, thepieces, depth - 1, alpha, beta, "black", thegame, hashvalue, aichosenmove);
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
        std::vector<std::pair<char, std::vector<int>>> possiblemoves = getallpossiblemoves(maximizingPlayer, underboard,
                                                                                           thepieces, false, thegame);
        //getallpossiblemoves will handle move types like enpassant, promotion
        King jking(0, 0, -9000, -9000);
        std::pair<int, int> ourking = jking.findking(maximizingPlayer, underboard, thepieces);
        std::vector<std::pair<int, int>> currcheckmoves;
        jking.setstartpos(ourking.first, ourking.second);
        jking.CastleCheckGeneration(underboard, thepieces, currcheckmoves, maximizingPlayer);
        for (auto item: currcheckmoves)
        {
            std::vector<int> currmove = {ourking.first, ourking.second, item.first, item.second, CASTLE};
            std::pair<char, std::vector<int>> castlepairs = std::make_pair('A', currmove);
            possiblemoves.emplace_back(castlepairs);
        }
        Player matter;
        for (std::pair<char, std::vector<int>> &move: possiblemoves)
        {
            std::vector<std::vector<char>> prevboard = underboard;
            std::vector<std::vector<Pieces>> prevpieces = thepieces;
            if (move.second.size() == 5 and move.second[4] == CASTLE)
            {
                King tempking(move.second[1], move.second[0], move.second[3], move.second[2]);
                tempking.CastleMovement(underboard, thepieces);
            } else
            {
                thegame.move(underboard, thepieces, maximizingPlayer, move.second[0], move.second[1], move.second[2],
                             move.second[3], matter);
            }
            if (move.first == 'P' and move.second[2] == 7)
            {
                updatepiece(underboard, thepieces, move.second[3], move.second[4], 'Q');
            }
            int eval = minimaxalphabeta(underboard, thepieces, depth - 1, alpha, beta, "white", thegame, hashvalue, aichosenmove);
            underboard = prevboard;
            thepieces = prevpieces;
            if (eval < minEvaluation and depth == 3)
            {
                minEvaluation = eval;
                aichosenmove = move;
            } else if (eval < minEvaluation)
            {
                minEvaluation = eval;
            }
            beta = std::min(beta, eval);
            if (beta <= alpha)
            {
                break;
            }
        }
        return minEvaluation;
    }
}


int Chess::MediumAi::quietsearch(std::vector<std::vector<char>> underboard,
                                 std::vector<std::vector<Pieces>> thepieces, int alpha, int beta,
                                 std::string maximizingPlayer, Game &thegame, int newdepth) {
    //int Chess::MediumAi::staticeval(std::vector<std::vector<char>> underboard, std::vector<std::vector<Pieces>> thepieces, std::string color)
    //make sure to deal with depth later
    if (newdepth == 0 or thegame.checkmate(maximizingPlayer, -9000, 9000))
    {
        return staticeval(underboard, thepieces,maximizingPlayer);
    }
    std::vector<std::pair<char, std::vector<int>>> possiblemoves = getallpossiblemoves(maximizingPlayer, underboard,
                                                                                       thepieces, true, thegame);
    std::cout << "Quiet search possiblemoves: " << possiblemoves.size() << std::endl;
    if (possiblemoves.size() == 0)
    {
        return staticeval(underboard, thepieces,maximizingPlayer);
    }
    if (maximizingPlayer == "white")
    {
        int standing_pateval = staticeval(underboard, thepieces, maximizingPlayer);
        if (standing_pateval >= beta)
        {
            return beta;
        }
        if (alpha < standing_pateval)
        {
            alpha = standing_pateval;
        }
        Player matter;
        for (auto capturemoves: possiblemoves)
        {
            std::vector<std::vector<char>> prevboard = underboard;
            std::vector<std::vector<Pieces>> prevpieces = thepieces;
            thegame.move(underboard, thepieces, maximizingPlayer, capturemoves.second[0], capturemoves.second[1],
                         capturemoves.second[2], capturemoves.second[3], matter);
            int evalscore = quietsearch(underboard, thepieces, alpha, beta, "black", thegame, newdepth - 1);
            underboard = prevboard;
            thepieces = prevpieces;

            if (evalscore >= beta)
            {
                return beta;
            }
            if (evalscore > alpha)
            {
                alpha = evalscore;
            }
        }
        return alpha;
    } else
    {
        int standing_pateval = staticeval(underboard, thepieces, maximizingPlayer);
        if (standing_pateval <= alpha)
        {
            return alpha;
        }
        if (standing_pateval < beta)
        {
            beta = standing_pateval;
        }
        Player matter;
        for (auto capturemoves: possiblemoves)
        {
            std::vector<std::vector<char>> prevboard = underboard;
            std::vector<std::vector<Pieces>> prevpieces = thepieces;
            thegame.move(underboard, thepieces, maximizingPlayer, capturemoves.second[0], capturemoves.second[1],
                         capturemoves.second[2], capturemoves.second[3], matter);
            int evalscore = quietsearch(underboard, thepieces, alpha, beta, "white", thegame, newdepth - 1);
            underboard = prevboard;
            thepieces = prevpieces;
            if (evalscore <= alpha)
            {
                return alpha;
            }
            if (evalscore < beta)
            {
                beta = standing_pateval;
            }
        }
        return beta;
    }
}


unsigned long long int
Chess::MediumAi::makemove(std::vector<std::vector<char>> &underboard, std::vector<std::vector<Pieces>> &thepieces,
                          unsigned long long int hashval,
                          int startposy, int startposx, int endposy, int endposx, char piece, std::string color) {
    hashval ^= ZobristTable[startposy][startposx][zorbistpieceindex(underboard[startposy][startposx],
                                                                    thepieces[startposy][startposx].getcolor())];
    hashval ^= ZobristTable[endposy][endposx][zorbistpieceindex(piece, color)];
    if (thepieces[endposy][endposx].getcolor() != color and underboard[endposy][endposx] != 'A'
        and underboard[endposy][endposx] != ' ')
    {
        hashval ^= ZobristTable[endposy][endposx][zorbistpieceindex(underboard[startposy][startposx],
                                                                    thepieces[startposy][startposx].getcolor())];
    }
    return hashval;
}


void Chess::MediumAi::InitalizeZorbistTable() {
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            for (int k = 0; k < 12; k++)
            {
                unsigned long long int value = 0;
                value = value - 1;
                ZobristTable[i][j][k] = rand() % value - 1;
            }
        }
    }
}


unsigned long long int Chess::MediumAi::createhashboardpos(std::vector<std::vector<char>> &underboard,
                                                           std::vector<std::vector<Pieces>> &thepieces) {
    unsigned long long int hash = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (underboard[i][j] != ' ')
            {
                int thepieceindex = zorbistpieceindex(underboard[i][j], thepieces[i][j].getcolor());
                hash ^= ZobristTable[i][j][thepieceindex];
            }
        }
    }
    return hash;
}


void
Chess::MediumAi::updatepiece(std::vector<std::vector<char>> &underboard, std::vector<std::vector<Pieces>> &thepieces,
                             int endposrow, int endposcol, char piece) {
    underboard[endposrow][endposcol] = piece;
    thepieces[endposrow][endposcol].settype(piece);
}


//Pawn King Bishop Rook Queen Knight
int Chess::MediumAi::zorbistpieceindex(char item, std::string color) {
    if (color == "white")
    {
        switch (item)
        {
            case 'P':
                return 0;
            case 'A':
                return 1;
            case 'B':
                return 2;
            case 'R':
                return 3;
            case 'Q':
                return 4;
            case 'K':
                return 5;
        }
    } else
    {
        switch (item)
        {
            case 'P':
                return 6;
            case 'A':
                return 7;
            case 'B':
                return 8;
            case 'R':
                return 9;
            case 'Q':
                return 10;
            case 'K':
                return 11;
        }
    }
    return -1;
}

bool Chess::MediumAi::currentlyincheck(std::vector<std::vector<char>> underboard,
                                       std::vector<std::vector<Pieces>> thepieces, std::string colorturn, int endposy, int endposx)
{
    Game newgame;
    std::pair<int, int> kingcoords = newgame.findking(colorturn, underboard, thepieces);
    King kingobj(kingcoords.second, kingcoords.first, endposx, endposy);
    if (kingobj.determinecheck(underboard, thepieces, colorturn))
    {
        return true;
    } else
    {
        return false;
    }
}



void Chess::MediumAi::grabpiecemoves(int i, int j, bool needscaptures, std::vector<std::vector<char>> underboard, std::vector<std::vector<Pieces>> thepieces, std::string color,  std::vector<std::pair<char, std::vector<int>>>& allpossiblemoves) {
    Pawn pawnobj(0, 0, -9000, -9000);
    Rook rookobj(0, 0, -9000, -9000);
    Knight knightobj(0, 0, -9000, -9000);
    King kingobj(0, 0, -9000, -9000);
    Queen queenobj(0, 0, -9000, -9000);
    Bishop bishopobj(0, 0, -9000, -9000);
    switch (underboard[i][j])
    {
        case 'P':
            pawnobj.setstartpos(i, j);
            pawnobj.GenerateMoves(underboard, thepieces, color);
            if (needscaptures)
            {
                for (auto item: pawnobj.getcapturemoves())
                {
                    if (currentlyincheck(underboard, thepieces, color, 0, 0))
                    {
                        continue;
                    }
                    std::vector<int> moves;
                    moves.push_back(i);
                    moves.push_back(j);
                    moves.push_back(item.first);
                    moves.push_back(item.second);
                    std::pair<char, std::vector<int>> movecomb = std::make_pair(underboard[i][j], moves);
                    allpossiblemoves.push_back(movecomb);
                }
            } else
            {
                for (auto item: pawnobj.getpossiblemoves())
                {
                    if (currentlyincheck(underboard, thepieces, color, 0, 0))
                    {
                        continue;
                    }
                    std::vector<int> moves;
                    moves.push_back(i);
                    moves.push_back(j);
                    moves.push_back(item.first);
                    moves.push_back(item.second);
                    std::pair<char, std::vector<int>> movecomb = std::make_pair(underboard[i][j], moves);
                    allpossiblemoves.push_back(movecomb);
                }
            }
            break;
        case 'R':
            rookobj.setstartpos(i, j);
            rookobj.GenerateMoves(underboard, thepieces, color);
            rookobj.getpossiblemoves();
            if (needscaptures)
            {
                for (auto item: rookobj.getcapturemoves())
                {
                    if (currentlyincheck(underboard, thepieces, color, 0, 0))
                    {
                        continue;
                    }
                    std::vector<int> moves;
                    moves.push_back(i);
                    moves.push_back(j);
                    moves.push_back(item.first);
                    moves.push_back(item.second);
                    std::pair<char, std::vector<int>> movecomb = std::make_pair(underboard[i][j], moves);
                    allpossiblemoves.push_back(movecomb);
                }
            } else
            {
                for (auto item: rookobj.getpossiblemoves())
                {
                    if (currentlyincheck(underboard, thepieces, color, 0, 0))
                    {
                        continue;
                    }
                    std::vector<int> moves;
                    moves.push_back(i);
                    moves.push_back(j);
                    moves.push_back(item.first);
                    moves.push_back(item.second);
                    std::pair<char, std::vector<int>> movecomb = std::make_pair(underboard[i][j], moves);
                    allpossiblemoves.push_back(movecomb);
                }
            }
            break;
        case 'K':
            knightobj.setstartpos(i, j);
            knightobj.GenerateMoves(underboard, thepieces, color);
            knightobj.getpossiblemoves();
            if (needscaptures)
            {
                for (auto item: knightobj.getcapturemoves())
                {
                    if (currentlyincheck(underboard, thepieces, color, 0, 0))
                    {
                        continue;
                    }
                    std::vector<int> moves;
                    moves.push_back(i);
                    moves.push_back(j);
                    moves.push_back(item.first);
                    moves.push_back(item.second);
                    std::pair<char, std::vector<int>> movecomb = std::make_pair(underboard[i][j], moves);
                    allpossiblemoves.push_back(movecomb);
                }
            } else
            {
                for (auto item: knightobj.getpossiblemoves())
                {
                    if (currentlyincheck(underboard, thepieces, color, 0, 0))
                    {
                        continue;
                    }
                    std::vector<int> moves;
                    moves.push_back(i);
                    moves.push_back(j);
                    moves.push_back(item.first);
                    moves.push_back(item.second);
                    std::pair<char, std::vector<int>> movecomb = std::make_pair(underboard[i][j], moves);
                    allpossiblemoves.push_back(movecomb);
                }
            }
            break;
        case 'B':
            bishopobj.setstartpos(i, j);
            bishopobj.GenerateMoves(underboard, thepieces, color);
            bishopobj.getpossiblemoves();
            if (needscaptures)
            {
                for (auto item: bishopobj.getcapturemoves())
                {
                    if (currentlyincheck(underboard, thepieces, color, 0, 0))
                    {
                        continue;
                    }
                    std::vector<int> moves;
                    moves.push_back(i);
                    moves.push_back(j);
                    moves.push_back(item.first);
                    moves.push_back(item.second);
                    std::pair<char, std::vector<int>> movecomb = std::make_pair(underboard[i][j], moves);
                    allpossiblemoves.push_back(movecomb);
                }
            } else
            {
                for (auto item: bishopobj.getpossiblemoves())
                {
                    if (currentlyincheck(underboard, thepieces, color, 0, 0))
                    {
                        continue;
                    }
                    std::vector<int> moves;
                    moves.push_back(i);
                    moves.push_back(j);
                    moves.push_back(item.first);
                    moves.push_back(item.second);
                    std::pair<char, std::vector<int>> movecomb = std::make_pair(underboard[i][j], moves);
                    allpossiblemoves.push_back(movecomb);
                }
            }
            break;
        case 'Q':
            queenobj.setstartpos(i, j);
            queenobj.GenerateMoves(underboard, thepieces, color);
            queenobj.getpossiblemoves();
            if (needscaptures)
            {
                for (auto item: queenobj.getcapturemoves())
                {
                    if (currentlyincheck(underboard, thepieces, color, 0, 0))
                    {
                        continue;
                    }
                    std::vector<int> moves;
                    moves.push_back(i);
                    moves.push_back(j);
                    moves.push_back(item.first);
                    moves.push_back(item.second);
                    std::pair<char, std::vector<int>> movecomb = std::make_pair(underboard[i][j], moves);
                    allpossiblemoves.push_back(movecomb);
                }
            } else
            {
                for (auto item: queenobj.getpossiblemoves())
                {
                    if (currentlyincheck(underboard, thepieces, color, 0, 0))
                    {
                        continue;
                    }
                    std::vector<int> moves;
                    moves.push_back(i);
                    moves.push_back(j);
                    moves.push_back(item.first);
                    moves.push_back(item.second);
                    std::pair<char, std::vector<int>> movecomb = std::make_pair(underboard[i][j], moves);
                    allpossiblemoves.push_back(movecomb);
                }
            }
            break;
        case 'A':
            kingobj.setstartpos(i, j);
            kingobj.GenerateMoves(underboard, thepieces, color);
            kingobj.getpossiblemoves();
            if (needscaptures)
            {
                for (auto item: kingobj.getcapturemoves())
                {
                    if (currentlyincheck(underboard, thepieces, color, 0, 0))
                    {
                        continue;
                    }
                    std::vector<int> moves;
                    moves.push_back(i);
                    moves.push_back(j);
                    moves.push_back(item.first);
                    moves.push_back(item.second);
                    std::pair<char, std::vector<int>> movecomb = std::make_pair(underboard[i][j], moves);
                    allpossiblemoves.push_back(movecomb);
                }
            } else
            {
                for (auto item: kingobj.getpossiblemoves())
                {
                    if (currentlyincheck(underboard, thepieces, color, 0, 0))
                    {
                        continue;
                    }
                    std::vector<int> moves;
                    moves.push_back(i);
                    moves.push_back(j);
                    moves.push_back(item.first);
                    moves.push_back(item.second);
                    std::pair<char, std::vector<int>> movecomb = std::make_pair(underboard[i][j], moves);
                    allpossiblemoves.push_back(movecomb);
                }

            }
    }
}


std::vector<std::pair<char, std::vector<int>>>
Chess::MediumAi::getallpossiblemoves(std::string color, std::vector<std::vector<char>> underboard,
                                     std::vector<std::vector<Pieces>> thepieces, bool needscaptures, Game& thegame) {
    std::vector<std::pair<char, std::vector<int>>> allpossiblemoves;
    //special moves I need to add:
    //castling, en passant, promotion
    for (int i = 0; i < underboard.size(); i++)
    {
        for (int j = 0; j < underboard[0].size(); j++)
        {
            if (thepieces[i][j].getcolor() == color and underboard[i][j] != ' ')
            {
                //int i, int j, bool needscaptures, std::vector<std::vector<char>> underboard, std::vector<std::vector<Pieces>> thepieces,
                // std::string color,  std::vector<std::pair<char, std::vector<int>>>& allpossiblemoves
                grabpiecemoves(i, j, needscaptures, underboard, thepieces, color, allpossiblemoves);
            }
        }
    }
    return allpossiblemoves;
}



