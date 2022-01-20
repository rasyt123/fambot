//
// Created by rasyt on 12/20/2021.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "Pawn.h"
#include "King.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "Knight.h"
#include "Pieces.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#define BOARD_ROWS 8
#define BOARD_COLS 8
#define OUT_OF_BOUNDS -9000

namespace Chess {
    class Game {
    public:
        void SetupBoard(sf::RenderWindow* window);
        void CheckSelect(sf::RenderWindow* window, bool& isgreen,  std::pair<float, float>& piececoords, std::pair<int, int>& pieceyx, bool mademove, float& clickposy, float& clickposx);
        void CoverCellGreen(sf::RenderWindow *window, bool &isgreen, std::pair<float, float> &piececoords, std::pair<int, int> &pieceyx, float& clickposy, float& clickposx);
        void HighlightPromotion(sf::RenderWindow *window, Pawn& pawnobj, int endposy, int endposx, std::string turn, bool& promotionmove);
        bool MakeMovePlayer(sf::RenderWindow *window, std::string colorturn, std::pair<int, int> startpieceyx, std::pair<int, int> endpieceyx, Player& currentplayer, bool& promotion);
        bool isTurn(int counter);
        bool currentlyincheck(sf::RenderWindow *window, std::string colorturn, bool& mademove, int endposy, int endposx, Player currentplayer, bool& incheck);
        bool checkmate(std::string colorturn, int endposy, int endposx);
        void move(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string turn, int startposy, int startposx, int endposy, int endposx, Player& currentplayer);
        bool IsValidMove(int row, int col, std::vector<std::pair<int, int>> possiblemoves);
        void GameLoop();
        void addcoords();
        void set_cellwidth(int width);
        void set_cellheight(int height);
        void SetUnderBoard();
        bool isPiece(float y, float x, std::pair<float, float>& piececords, std::pair<int, int>& boardcords);
        bool isPiece2(float y, float x, std::pair<int, int>& boardcords);
        bool isEven(int number);
        void printPiece(float spritex, float spritey, int ypos, int xpos, sf::RenderWindow* window, std::string color);
        void updatepiece(int endposrow, int endposcol, char piece);
        bool samecoords(float curry, float currx, float comparisony, float comparisonx);
        std::pair<int,int> returnendpos(sf::RenderWindow* window, std::string color, int clickposy, int clickposx);
        std::pair<int, int> findking(std::string color, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces);
        bool checkpawnmovetwice(int startposy, int startposx, int endposy, int endposx, std::string turn, Pawn pawnobj);

    private:
        std::string currentturn = "white";
        std::vector<std::vector<std::pair<float, float>>> boardcoords;
        std::vector<std::vector<char>> underboard;
        std::vector<std::vector<Pieces>> thepieces;
        std::vector<std::vector<int>> pawnmovetwicewhite;
        std::vector<std::string> pawninformationwhite;

        std::vector<std::vector<int>> pawnmovetwiceblack;
        std::vector<std::string> pawninformationblack;


        int cell_width;
        int cell_height;
        int currturncount = 0;


    };

}


#endif //CHESS_GAME_H
