//
// Created by rasyt on 12/20/2021.
//

#include "Game.h"


bool Game::isEven(int number) {
    if (number % 2 == 0) {
        return true;
    } else {
        return false;
    }
}


void Game::set_cellheight(int height) {
    cell_height = height;
}


void Game::set_cellwidth(int width) {
    cell_width = width;

}

void Game::GameLoop() {
    sf::RenderWindow window(sf::VideoMode(1200, 1200), "Chess", sf::Style::Close | sf::Style::Titlebar);
    addcoords();
    bool mademove = false;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }
        }
        window.clear();
        SetupBoard(1200, 1200, &window);
        window.display();
    }
}



void Game::SetUnderBoard() {
    underboard = {
            {'R', 'K', 'B', 'Q', 'A', 'B', 'K', 'R'},
            {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
            {'R', 'K', 'B', 'Q', 'A', 'B', 'K', 'R'}
    };
}


void Game::addcoords() {
    std::vector<std::pair<float, float>> rowcoords;
    for (int y = 0; y < BOARD_ROWS; y++) {
        for (int x = 0; x < BOARD_COLS; x++) {
            float cellxpos = x * cell_width;
            float cellypos = y * cell_height;
            rowcoords.emplace_back(std::make_pair(cellxpos, cellypos));
            if (x == BOARD_COLS) {
                rowcoords = {};
                boardcoords.push_back(rowcoords);
            }
        }
    }
}




void Game::SetupBoard(int boardwidth, int boardheight, sf::RenderWindow* window) {
    std::vector<std::pair<float, float>> rowcoords;
    bool isempty = false;
    std::string imagedir = "C:\\Users\\rasyt\\Pictures\\Saved Pictures\\";
    std::string black = "b";
    std::string white = "w";
    for (int y = 0; y < BOARD_ROWS; y++) {
        for (int x = 0; x < BOARD_COLS; x++) {
            float cellxpos = x * cell_width;
            float cellypos = y * cell_height;
            float spritex = cellxpos + cell_width / 2;
            float spritey = cellypos + cell_height / 2;
            sf::Texture texture;
            if (y <= 1) {
                imagedir += white;
            } else {
                imagedir += black;
            }
            switch (underboard[x][y]) {
                case 'P':
                    imagedir += "_pawn_png_128px";
                    texture.loadFromFile(imagedir);
                    break;
                case 'R':
                    imagedir += "_rook_png_128px";
                    texture.loadFromFile(imagedir);
                    break;
                case 'K':
                    imagedir += "_knight_png_128px";
                    texture.loadFromFile(imagedir);
                    break;
                case 'B':
                    imagedir += "_bishop_png_128px";
                    texture.loadFromFile(imagedir);
                    break;
                case 'A':
                    imagedir += "_king_png_128px";
                    texture.loadFromFile(imagedir);
                    break;
                case 'Q':
                    imagedir += "_queen_png_128px";
                    texture.loadFromFile(imagedir);
                    break;
                default:
                    isempty = true;
            }
            sf::Sprite sprite(texture);
            sprite.setPosition(spritex, spritey);
            sf::RectangleShape boardcell(sf::Vector2f(150.0f, 150.0f));
            if (isEven(y)) {
                if (isEven(x)) {
                    boardcell.setFillColor(sf::Color::White);
                } else {
                    boardcell.setFillColor(sf::Color::Black);
                }

            } else {
               if (isEven(x)) {
                   boardcell.setFillColor(sf::Color::Black);
               } else {
                   boardcell.setFillColor(sf::Color::White);
               }
            }
            boardcell.setPosition(cellxpos, cellypos);
            window->draw(boardcell);
            if (!isempty) {
                window->draw(sprite);
            }
            isempty = false;
            imagedir = "C:/Users/rasyt/Pictures/Saved Pictures/";
        }
    }
}
