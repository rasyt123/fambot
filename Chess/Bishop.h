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
        std::vector<std::pair<int,int>> getpossiblemoves();
        std::vector<std::pair<int, int>> getpossiblemovescpy();
        void clearmoves();

    private:
        bool hasking;
        int startposx;
        int startposy;
        int endposx;
        int endposy;
        std::vector<std::pair<int,int>> possiblemoves;
        std::vector<std::pair<int, int>> possiblemovescpy;


    };

}



#endif //CHESS_BISHOP_H



