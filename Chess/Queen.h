//
// Created by rasyt on 12/22/2021.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H
#include "Pieces.h"
#include "Rook.h"
#include "Bishop.h"

namespace Chess {
    class Queen : Pieces {
    public:
        void GenerateMoves(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        std::vector<std::pair<int,int>> getpossiblemoves();
        std::vector<std::pair<int, int>> getpossiblemovescpy();

    private:
        Rook rookmethod;
        Bishop bishopmethod;

        bool hasking;
        int startposx;
        int startposy;
        int endposx;
        int endposy;
        std::vector<std::pair<int,int>> possiblemoves;
        std::vector<std::pair<int,int>> possiblemovescpy;


    };
}



#endif //CHESS_QUEEN_H
