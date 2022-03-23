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
#include <set>
#include <vector>
#define ENPASSANT -10
#define CASTLE -10
namespace Chess {
    class MediumAi {



    public:
        bool inbounds(int row, int col);
        void whitesetPawnevalsquares();
        void whitesetKnightevalsquares();
        void whitesetBishopevalsquares();
        void whitesetRookevalsquares();
        void whitesetQueenevalsquares();
        void whitesetKingevalsquares();
        void endgamewhitesetkingevalsquares();
        void blacksetPawnevalsquares();
        void blacksetKnightevalsquares();
        void blacksetBishopevalsquares();
        void blacksetRookevalsquares();
        void blacksetQueenevalsquares();
        void blacksetKingevalsquares();
        void endgameblacksetkingevalsquares();
        int zorbistpieceindex(char item, std::string color);
        void InitalizeZorbistTable();

        bool isWatching(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color, int row, int col);
        int countpassedpawn(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        int countbackwardpawn(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color, Game& thegame);
        int countdoubledpawnscore(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        int countisolatedpawnscore(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        void updatepiece(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, int endposrow, int endposcol, char piece);
        std::vector<std::pair<char, std::vector<int>>> getallpossiblemoves(std::string color, std::vector<std::vector<char>> underboard,
        std::vector<std::vector<Pieces>> thepieces);
        int minimaxalphabeta(std::vector<std::vector<char>> underboard,
                             std::vector<std::vector<Pieces>> thepieces, int depth, int alpha, int beta, std::string maximizingPlayer, Game& thegame);
        int staticeval(std::vector<std::vector<char>> underboard,
                       std::vector<std::vector<Pieces>> thepieces, std::string color);




    private:
        //Eval Function
        //Square Piece Tables
        std::vector<std::vector<int>> pawnevalsquares;
        std::vector<std::vector<int>> knightevalsquares;
        std::vector<std::vector<int>> bishopevalsquares;
        std::vector<std::vector<int>> rookevalsquares;
        std::vector<std::vector<int>> queenevalsquares;
        std::vector<std::vector<int>> kingevalsquares;
        std::vector<std::vector<int>> endgamekingevalsquares;
        unsigned long long int ZobristTable[8][8][12];
        std::set<int> zorbisthash;
        std::vector<std::vector<int>> blackpawnevalsquares;
        std::vector<std::vector<int>> blackknightevalsquares;
        std::vector<std::vector<int>> blackbishopevalsquares;
        std::vector<std::vector<int>> blackrookevalsquares;
        std::vector<std::vector<int>> blackqueenevalsquares;
        std::vector<std::vector<int>> blackkingevalsquares;
        std::vector<std::vector<int>> blackendgamekingevalsquares;
    };






}


#endif //CHESS_MEDIUMAI_H


