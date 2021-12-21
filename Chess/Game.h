//
// Created by rasyt on 12/20/2021.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#define BOARD_ROWS 8
#define BOARD_COLS 8
#define OUT_OF_BOUNDS -9000
namespace Chess {
    class Game {
    public:
        void SetupBoard(sf::RenderWindow* window);
        void CheckSelect(sf::RenderWindow* window, bool& isgreen,  std::pair<float, float>& piececoords, std::pair<int, int>& pieceyx);
        void GameLoop();
        void addcoords();
        void set_cellwidth(int width);
        void set_cellheight(int height);
        void SetUnderBoard();
        bool isPiece(float y, float x, std::pair<float, float>& piececords, std::pair<int, int>& boardcords);
        bool isEven(int number);



    private:

        std::vector<std::vector<std::pair<float, float>>> boardcoords;
        std::vector<std::vector<char>> underboard;
        int cell_width;
        int cell_height;
        double window_height;
        double window_width;

        int old_greenposx;
        int old_greenposy;
    };

}


#endif //CHESS_GAME_H
