//
// Created by rasyt on 12/22/2021.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H
#include "Pieces.h"

namespace Chess {
    class Pawn : Pieces {
        public:
        Pawn(int x, int y) {
            startposx = x;
            startposy = y;
        }
        void GenerateMoves(sf::RenderWindow* window, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        void EnPassant(sf::RenderWindow* window, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        void Capture(sf::RenderWindow* window, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        void ListPromotionOptions(sf::RenderWindow* window, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string color);
        bool InBounds(int row, int col, std::vector<std::vector<char>>& underboard);
        bool IsValidMove(int row, int col);
        void GenerateWhite(std::vector<std::vector<char>>& underboard);
        void GenerateBlack(std::vector<std::vector<char>>& underboard);
        bool BottomLeft(std::vector<std::vector<char>>& underboard);
        bool BottomRight(std::vector<std::vector<char>>& underboard);
        bool infrontdown(std::vector<std::vector<char>>& underboard);
        bool infront2down(std::vector<std::vector<char>>& underboard);
        bool TopLeft(std::vector<std::vector<char>>& underboard);
        bool TopRight(std::vector<std::vector<char>>& underboard);
        bool infronttop(std::vector<std::vector<char>>& underboard);
        bool infront2top(std::vector<std::vector<char>>& underboard);



        private:
            int startposx;
            int startposy;
            int endposx;
            int endposy;
            vector<pair<int,int>> possiblemoves;

    };
}


#endif //CHESS_PAWN_H
