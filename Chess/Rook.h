//
// Created by rasyt on 12/22/2021.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H
#include "Pieces.h"
namespace Chess {
    class Rook : Pieces {
        public:
        Rook(int startposxx, int startposyy, int endposxx, int endposyy) {
            startposx = startposxx;
            startposy = startposyy;
            endposx = endposxx;
            endposy = endposyy;
        }
        Rook() {

        }
            std::vector<std::pair<int,int>>& getpossiblemoves();
            std::vector<std::pair<int, int>> getpossiblemovescpy();

            bool GenerateMoves(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
            bool gettop(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color, int posy, int posx);
            bool getbottom(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color, int posy, int posx);
            bool getadjacentleft(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color, int posy, int posx);
            bool getadjacentright(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color, int posy, int posx);
            bool getstaredown();



    private:
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


#endif //CHESS_ROOK_H
