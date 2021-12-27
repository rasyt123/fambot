//
// Created by rasyt on 12/22/2021.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H
#include "Pieces.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"
#include "Rook.h"

namespace Chess {
    class King : public Pieces {
        public:
        //black castle
        //white castle
        //determining checkmate
        //determining checks
        //basic movement
        void GenerateMoves(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        void CastleMovement(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        bool performCastle(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        bool determinecheck(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        bool determinecheckmate(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        void generatemoves(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        void castlemove(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        void addmoves(std::vector<std::pair<int, int>> src, std::vector<std::pair<int, int>>& destination);
        void collectmoveinterference(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, Pawn& pawnobj, Rook& rookobj, Queen& queenobj,
                                     Bishop& bishopobj, King& kingobj, Knight& knightobj, int y, int x, std::string color);


        private:
            bool hasking;
            int startposx;
            int startposy;
            int endposx;
            int endposy;
            std::vector<std::pair<int, int>> interferemoves;
            std::vector<std::pair<int,int>> possiblemoves;
            std::vector<std::pair<int,int>> possiblemovescpy;

    };


}



#endif //CHESS_KING_H
