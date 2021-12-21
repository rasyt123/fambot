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

bool Game::isPiece(float y, float x) {

}

void Game::GameLoop() {
    sf::RenderWindow window(sf::VideoMode(960, 960), "Chess", sf::Style::Close | sf::Style::Titlebar);
    addcoords();
    bool mademove = false;
    bool isgreen = false;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) and isgreen) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            if (isPiece(mousePos.y, mousePos.x)) {
                
            }

        } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {


            isgreen = true;
        }
        window.clear();
        SetupBoard(960, 960, &window);
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
            float spritex = cellxpos + (26);
            float spritey = cellypos + (26);
            sf::Texture texture;
            if (y <= 1) {
                imagedir += white;
            } else {
                imagedir += black;
            }
            switch (underboard[y][x]) {
                case 'P':
                    imagedir += "_P60.png";
                    texture.loadFromFile(imagedir);
                    break;
                case 'R':
                    imagedir += "_R60.png";
                    texture.loadFromFile(imagedir);
                    break;
                case 'K':
                    imagedir += "_K60.png";
                    texture.loadFromFile(imagedir);
                    break;
                case 'B':
                    imagedir += "_b60.png";
                    texture.loadFromFile(imagedir);
                    break;
                case 'A':
                    imagedir += "_A60.png";
                    texture.loadFromFile(imagedir);
                    break;
                case 'Q':
                    imagedir += "_Q60.png";
                    texture.loadFromFile(imagedir);
                    break;
                default:
                    isempty = true;
            }
            sf::Sprite sprite(texture);
            sprite.setPosition(spritex, spritey);
            sf::RectangleShape boardcell(sf::Vector2f(120.0f, 120.0f));
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
            imagedir = "C:\\Users\\rasyt\\Pictures\\Saved Pictures\\";
        }
    }
}
