//
// Created by rasyt on 12/21/2021.
//

#ifndef CHESS_PIECES_H
#define CHESS_PIECES_H
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
namespace Chess {
    class Pieces {
        public:
            void setcolor(std::string thecolor);
            void settype(char thetype);
            void setblank(bool val);
            char gettype();
            std::string getcolor();
            bool getblank();
            bool InBounds(int row, int col, std::vector<std::vector<char>>& underboard);

        private:
            std::string color;
            char type;
            bool blank = false;
    };
}



#endif //CHESS_PIECES_H
