//
// Created by rasyt on 12/22/2021.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H
#include "Pieces.h"
namespace Chess {
    class Bishop : Pieces {
        public:
        bool GenerateMoves(sf::RenderWindow* window, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        void grabmovetopleft(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        void grabmovetopright(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        void grabmovebottomleft(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        void grabmovebottomright(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);


        private:
            int startposx;
            int startposy;
            int endposx;
            int endposy;
            std::vector<std::pair<int,int>> possiblemoves;


    };

}



#endif //CHESS_BISHOP_H
