//
// Created by rasyt on 12/22/2021.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H
#include "Pieces.h"
#include <iostream>

namespace Chess {
    class Pawn : Pieces {
        public:
        Pawn(int x, int y, int endposxx, int endposyy) {
            startposx = x;
            startposy = y;
            endposx = endposxx;
            endposy = endposyy;
        }
        Pawn() {

        }
        bool GenerateMoves(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        void EnactPassant(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces);
        void ListPromotionOptions(sf::RenderWindow* window, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string turn, std::vector<std::vector<std::pair<float, float>>>& boardcoords, bool& promotion);
        void drawPromotions(sf::RenderWindow* window, std::vector<std::string> promotionimgs, std::vector<std::vector<char>>& underboard, std::pair<float, float> cellcoords);
        bool IsValidMove(int rows, int cols);
        void EnPassant(sf::RenderWindow* window, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string turn, bool& passant,  std::vector<std::vector<int>>& pawnmovetwicewhite,
        std::vector<std::vector<int>>& pawnmovetwiceblack);
        void GenerateWhite(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces);
        void GenerateBlack(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces);
        bool BottomLeft(std::vector<std::vector<char>>& underboard);
        bool BottomRight(std::vector<std::vector<char>>& underboard);
        bool infrontdown(std::vector<std::vector<char>>& underboard);
        bool infront2down(std::vector<std::vector<char>>& underboard);
        bool TopLeft(std::vector<std::vector<char>>& underboard);
        bool TopRight(std::vector<std::vector<char>>& underboard);
        bool infronttop(std::vector<std::vector<char>>& underboard);
        bool infront2top(std::vector<std::vector<char>>& underboard);
        bool passantcheck(std::vector<std::vector<int>>& pawnmoveslist, int pawnnexty, int pawnnextx);

        void createblank(int posy, int posx, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces);
        std::vector<std::pair<int,int>> getpossiblemoves();
        std::vector<std::pair<int, int>> getpossiblemovescpy();
        bool getstaredown();

    private:
            int startposx;
            int startposy;
            int endposx;
            int endposy;
            int prevposy;
            int prevposx;
            bool starekingdown = false;
        std::vector<std::pair<int,int>> possiblemoves;
        std::vector<std::pair<int,int>> possiblemovescpy;

    };
}


#endif //CHESS_PAWN_H
