//
// Created by rasyt on 12/22/2021.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H
#include "Pieces.h"
namespace Chess {
    class Rook : Pieces {
        public:
            std::vector<std::pair<int,int>> getpossiblemoves();
            std::vector<std::pair<int, int>> getpossiblemovescpy();

            bool GenerateMoves(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
            void gettop(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color, int posy, int posx);
            void getbottom(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color, int posy, int posx);
            void getadjacentleft(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color, int posy, int posx);
            void getadjacentright(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color, int posy, int posx);

        private:
            bool hasking;
            int startposx;
            int startposy;
            int endposx;
            int endposy;
            std::vector<std::pair<int,int>> possiblemoves;
            std::vector<std::pair<int,int>> possiblemovescpy;
    };
}


#endif //CHESS_ROOK_H
