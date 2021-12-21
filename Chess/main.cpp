#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"


int main() {
    Game chess;
    chess.SetUnderBoard();
    chess.set_cellwidth(150);
    chess.set_cellheight(150);
    chess.GameLoop();






}
