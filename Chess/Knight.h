//
// Created by rasyt on 12/24/2021.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H
#include "Pieces.h"
namespace Chess {
    class Knight : Pieces {
        public:
        Knight(int startposxx, int startposyy, int endposxx, int endposyy) {
            startposx = startposxx;
            startposy = startposyy;
            endposx = endposxx;
            endposy = endposyy;
        }
        Knight() {

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


#endif //CHESS_KNIGHT_H
