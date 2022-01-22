//
// Created by rasyt on 12/22/2021.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H
#include "Pieces.h"
#include "Rook.h"
#include "Bishop.h"
#include <iostream>

namespace Chess {
    class Queen : Pieces {
    public:
        Queen(int startposxx, int startposyy, int endposxx, int endposyy) {
            startposx = startposxx;
            startposy = startposyy;
            endposx = endposxx;
            endposy = endposyy;
        }
        Queen () {


        }
        bool GenerateMoves(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        std::vector<std::pair<int,int>>& getpossiblemoves();
        std::vector<std::pair<int, int>> getpossiblemovescpy();
        bool getstaredown();
    private:
        bool isprotected = false;
        bool hasking;
        int startposx;
        int startposy;
        int endposx;
        int endposy;
        bool starekingdown = false;
        std::vector<std::pair<int,int>> possiblemoves;
        std::vector<std::pair<int,int>> possiblemovescpy;


    };
}



#endif //CHESS_QUEEN_H
