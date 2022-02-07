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
#include <iostream>

namespace Chess {
    class King : public Pieces {
        public:
        //black castle
        //white castle
        //determining checkmate
        //determining checks)
        //basic movement
        King (int sposx, int sposy, int eposx, int eposy) {
            startposx = sposx;
            startposy = sposy;
            endposx = eposx;
            endposy = eposy;
        }
        King() {

        }
        std::vector<std::pair<int,int>> getpossiblemoves();
        void castleenact(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, int startposfactor, int kingcrement);
        void setblank(int ypos, int xpos, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces);
        bool CastleCheck(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        void GenerateMoves(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        void CastleMovement(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces);
        bool performCastle(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        bool determinecheck(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        bool determinecheckmate(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        void castlemove(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        void addmoves(std::vector<std::pair<int, int>> src, std::vector<std::pair<int, int>>& destination);
        bool collectmoveinterference(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, int y, int x, std::string color);
        void collectmoveinterference2(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, int y, int x, std::string color, std::vector<std::pair<int, int>>& addedmoves);
        std::vector<std::pair<int,int>> grabopposingkingssquares(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, int y, int x, std::string color);

        bool determinestalemate(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        void clearpossiblemoves();
        bool cannotblock(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        std::vector<int> grabstaredown(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        std::pair<int, int> findking(std::string color, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces);

        std::vector<std::pair<int, int>> protectingsquares;
        std::vector<std::pair<int, int>> totalprotectingsquares;


        bool cangobblenearking(int rowpos, int colpos, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        bool IsPieceProtected(int opppiecerowpos, int opppiececolpos);


        private:
            bool hasking = false;
            int startposx;
            int startposy;
            int endposx;
            int endposy;
            int currstarekingy = -9000;
            int currstarekingx = -9000;
            std::vector<std::pair<int, int>> interferemoves;
            std::vector<std::pair<int ,int>> interferemoves2;
            std::vector<std::pair<int,int>> possiblemoves;
            std::vector<std::pair<int,int>> possiblemovescpy;
            std::vector<std::pair<int, int>> watchingsquares;
            std::vector<std::pair<int, int>> markedsquarestaredown;


    };


}



#endif //CHESS_KING_H
