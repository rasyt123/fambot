//
// Created by rasyt on 12/22/2021.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H
#include "Pieces.h"
namespace Chess {
    class Bishop : Pieces {
    public:
        Bishop(int startposxx, int startposyy, int endposxx, int endposyy) {
            startposx = startposxx;
            startposy = startposyy;
            endposx = endposxx;
            endposy = endposyy;
        }
        Bishop() {


        }
        bool GenerateMoves(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        bool grabmovetopleft(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color, int posy, int posx);
        bool grabmovetopright(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color, int posy, int posx);
        bool grabmovebottomleft(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color, int posy, int posx);
        bool grabmovebottomright(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color, int posy, int posx);
        bool IsValidMove(int rows, int cols);
        bool KingCheck();
        std::vector<std::pair<int,int>>& getpossiblemoves();
        std::vector<std::pair<int, int>> getpossiblemovescpy();
        bool getstaredown();
        void clearmoves();
        int getstaredownkingy();
        int getstaredownkingx();

    private:
        bool hasking;
        int startposx;
        int startposy;
        int endposx;
        int endposy;
        bool isprotected = false;
        bool watchingkingsquare = false;
        bool starekingdown = false;
        int staredownkingy = -9000;
        int staredownkingx = -9000;
        std::vector<std::pair<int,int>> possiblemoves;
        std::vector<std::pair<int, int>> possiblemovescpy;
        std::vector<std::pair<int, int>> watchingsquares;


    };

}



#endif //CHESS_BISHOP_H



