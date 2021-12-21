//
// Created by rasyt on 12/20/2021.
//

#include "Game.h"

bool Chess::Game::isEven(int number) {
    if (number % 2 == 0) {
        return true;
    } else {
        return false;
    }
}


void Chess::Game::set_cellheight(int height) {
    cell_height = height;
}


void Chess::Game::set_cellwidth(int width) {
    cell_width = width;

}

bool Chess::Game::isPiece(float y, float x, std::pair<float, float>& piececords) {
    for (int height = 0; height < BOARD_ROWS; height++) {
        for (int width = 0; width < BOARD_COLS; width++) {
            float cellxpos = width * cell_width;
            float cellypos = height * cell_height;
            if (x > cellxpos and x < cellxpos + (float) cell_width and y > cellypos and y < cellypos + (float) cell_height) {
                if (underboard[height][width] != ' ') {
                    piececords = boardcoords[height][width];
                    return true;
                }
            }
        }
    }
    return false;
}

void Chess::Game::GameLoop() {
    sf::RenderWindow window(sf::VideoMode(960, 960), "Chess", sf::Style::Close | sf::Style::Titlebar);
    addcoords();
    bool mademove = false;
    bool isgreen = false;
    std::pair<float, float> piececoords;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }
        }
        CheckSelect(&window, isgreen);
        window.clear();
        SetupBoard(&window);
        window.display();
    }
}


void Chess::Game::CheckSelect(sf::RenderWindow* window, bool& isgreen,  std::pair<float, float>& piececoords) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) and isgreen) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
        if (isPiece((float) mousePos.y, (float)mousePos.x)) {

        }
        isgreen = false;
    } else if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
        if (isPiece((float) mousePos.y, (float) mousePos.x)) {

        }
        isgreen = true;
    }
}



void Chess::Game::SetUnderBoard() {
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


void Chess::Game::addcoords() {
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



void Chess::Game::SetupBoard(sf::RenderWindow* window) {
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
