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


class Game {
    public:
       void SetupBoard(int boardwidth, int boardheight, sf::RenderWindow* window);
       void GameLoop();
       void addcoords();
       void set_cellwidth(int width);
       void set_cellheight(int height);
       void SetUnderBoard();
       bool isEven(int number);



    private:

       std::vector<std::vector<std::pair<float, float>>> boardcoords;
       std::vector<std::vector<char>> underboard;
       int cell_width;
       int cell_height;
       double window_height;
       double window_width;
};


#endif //CHESS_GAME_H
