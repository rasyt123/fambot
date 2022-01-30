
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"


int main() {
    Chess::Game chess;
    chess.SetUnderBoard();
    chess.set_cellwidth(120);
    chess.set_cellheight(120);
    chess.GameLoop();






}
