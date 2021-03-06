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
        int getstaredownkingy();
        int getstaredownkingx();
        bool GenerateMoves(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        std::vector<std::pair<int,int>>& getpossiblemoves();
        std::vector<std::pair<int, int>> getpossiblemovescpy();
        bool getstaredown();
        std::vector<std::pair<int, int>> protectingsquares;


    private:
        bool isprotected = false;
        bool hasking;
        int startposx;
        int startposy;
        int endposx;
        int endposy;
        bool starekingdown = false;
        int staredownkingy;
        int staredownkingx;

        std::vector<std::pair<int,int>> possiblemoves;
        std::vector<std::pair<int,int>> possiblemovescpy;
        std::vector<std::pair<int, int>> watchingsquares;


    };
}



#endif //CHESS_QUEEN_H
