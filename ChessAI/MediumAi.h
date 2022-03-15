//
// Created by rasyt on 12/21/2021.
//
#include "King.h"
#include "Pawn.h"
#include "Rook.h"
#include "Queen.h"
#include "Knight.h"
#include "Pieces.h"
#include "Player.h"
#ifndef CHESS_MEDIUMAI_H
#define CHESS_MEDIUMAI_H
#include "Game.h"

#include <vector>

namespace Chess {
    class MediumAi {



    public:
        void whitesetPawnevalsquares();
        void whitesetKnightevalsquares();
        void whitesetBishopevalsquares();
        void whitesetRookevalsquares();
        void whitesetQueenevalsquares();
        void whitesetKingevalsquares();
        void blacksetPawnevalsquares();
        void blacksetKnightevalsquares();
        void blacksetBishopevalsquares();
        void blacksetRookevalsquares();
        void blacksetQueenevalsquares();
        void blacksetKingevalsquares();
        std::vector<std::pair<char, std::vector<int>>> getallpossiblemoves(std::string color, std::vector<std::vector<char>> underboard,
        std::vector<std::vector<Pieces>> thepieces);
        int minimaxalphabeta(std::vector<std::vector<char>> underboard,
                             std::vector<std::vector<Pieces>> thepieces, int depth, int alpha, int beta, std::string maximizingPlayer, Game& thegame);
        int staticeval(std::vector<std::vector<char>> underboard,
                       std::vector<std::vector<Pieces>> thepieces);




    private:
        //Eval Function
        //Square Piece Tables
        std::vector<std::vector<int>> pawnevalsquares;
        std::vector<std::vector<int>> knightevalsquares;
        std::vector<std::vector<int>> bishopevalsquares;
        std::vector<std::vector<int>> rookevalsquares;
        std::vector<std::vector<int>> queenevalsquares;
        std::vector<std::vector<int>> kingevalsquares;



        std::vector<std::vector<int>> blackpawnevalsquares;
        std::vector<std::vector<int>> blackknightevalsquares;
        std::vector<std::vector<int>> blackbishopevalsquares;
        std::vector<std::vector<int>> blackrookevalsquares;
        std::vector<std::vector<int>> blackqueenevalsquares;
        std::vector<std::vector<int>> blackkingevalsquares;

    };






}


#endif //CHESS_MEDIUMAI_H
