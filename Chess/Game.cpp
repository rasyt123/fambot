//
// Created by rasyt on 12/20/2021.
//

#include "Game.h"

bool Chess::Game::isPiece(float y, float x, std::pair<float, float>& piececords, std::pair<int, int>& boardcords) {
    for (int height = 0; height < BOARD_ROWS; height++)
    {
        for (int width = 0; width < BOARD_COLS; width++)
        {
            float cellxpos = width * cell_width;
            float cellypos = height * cell_height;
            if (x > cellxpos and x < cellxpos + (float) cell_width and y > cellypos and y < cellypos + (float) cell_height)
            {
                if (underboard[height][width] != ' ')
                {
                    piececords = boardcoords[height][width];
                    boardcords = std::make_pair(height, width);
                    return true;
                }
            }
        }
    }
    return false;
}

void Chess::Game::GameLoop() {
    sf::RenderWindow window(sf::VideoMode(960, 960), "Chess", sf::Style::Close | sf::Style::Titlebar);
    bool isgreen = false;
    bool mademove = false;
    std::pair<float, float> piececoords;
    std::pair<int, int> pieceyx;
    pieceyx.first = OUT_OF_BOUNDS;
    pieceyx.second = OUT_OF_BOUNDS;
    piececoords.first = OUT_OF_BOUNDS;
    piececoords.second = OUT_OF_BOUNDS;
    std::string turncolor = "white";
    addcoords();
    float clickposy = OUT_OF_BOUNDS;
    float clickposx = OUT_OF_BOUNDS;
    while (window.isOpen())
    {
        if (isEven(currturncount))
        {
            currentturn = "white";
        } else
        {
            currentturn = "black";
        }
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                break;
            }
        }
        window.clear();
        SetupBoard(&window);
        CheckSelect(&window, isgreen, piececoords, pieceyx, mademove, clickposy, clickposx);

        window.display();
        if (mademove)
        {
            currturncount += 1;
        }
    }
}

void Chess::Game::MakeMovePlayer(std::string turn, int posy, int posx, bool& mademove) {
    if (turn == "white")
    {
        switch(underboard[posy][posx])
        {
            case 'P':
                //generate possible moves
                break;
            case 'R':
                break;
            case 'K':
                break;
            case 'B':
                break;
            case 'A':
                break;
            case 'Q':
                break;

        }




    } else
    {



    }
}

void Chess::Game::Capture(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string turn, int startposy, int startposx, int endposy, int endposx) {
    char oldpiece = underboard[startposy][startposx];
    underboard[startposy][startposx] = ' ';
    underboard[endposy][endposx] = oldpiece;
    thepieces[endposy][endposx] = thepieces[startposy][startposx];
    thepieces[startposy][startposx].settype(' ');
    thepieces[startposy][startposx].setblank(true);
    thepieces[startposy][startposx].setcolor("");
}


void Chess::Game::HighlightPromotion(sf::RenderWindow *window, Pawn& pawnobj, int endposy, int endposx, std::string turn, bool& promotionmove) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
    std::vector<char> promoteopts = {'Q', 'B', 'R', 'K'};
    float clickposy = mousePos.y;
    float clickposx = mousePos.x;
    std::pair<float, float> promoteboxcoords;
    for (int dy = 0; dy < 4; dy++)
    {
        promoteboxcoords = boardcoords[endposy + dy][endposx];
        if (clickposx > promoteboxcoords.first and clickposx < promoteboxcoords.first + 120 and
            clickposy > promoteboxcoords.second and clickposy < promoteboxcoords.second + 120)
        {
            sf::RectangleShape greenbox(sf::Vector2f(120.0f, 120.0f));
            greenbox.setFillColor(sf::Color::Green);
            greenbox.setPosition(promoteboxcoords.first, promoteboxcoords.second);
            printPiece(promoteboxcoords.first + 26, promoteboxcoords.second + 26, endposy, endposx, window, thepieces[endposy][endposx].getcolor());
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                updatepiece(endposy, endposx, promoteopts[dy]);
                promotionmove = true;
            }
        }
    }
}

void Chess::Game::CheckSelect(sf::RenderWindow* window, bool& isgreen,  std::pair<float, float>& piececoords, std::pair<int, int>& pieceyx, bool mademove, float& clickposy, float& clickposx) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
        clickposy = mousePos.y;
        clickposx = mousePos.x;
        if (isPiece((float) mousePos.y, (float)mousePos.x, piececoords, pieceyx) and piececoords.first != -9000 and piececoords.second != -9000)
        {
            if (thepieces[pieceyx.first][pieceyx.second].getcolor() == currentturn)
            {
                CoverCellGreen(window, isgreen, piececoords, pieceyx, clickposy, clickposx);
            }
        }
    } else if (!mademove)
    {
        CoverCellGreen(window, isgreen, piececoords, pieceyx, clickposy, clickposx);
    }
    return;
}

void Chess::Game::CoverCellGreen(sf::RenderWindow *window, bool &isgreen, std::pair<float, float> &piececoords, std::pair<int, int> &pieceyx, float& clickposy, float& clickposx) {
    if (isPiece(clickposy, clickposx, piececoords, pieceyx) and piececoords.first != -9000 and piececoords.second != -9000
    and thepieces[pieceyx.first][pieceyx.second].getcolor() == currentturn)
    {
        sf::RectangleShape boardcell(sf::Vector2f(120.0f, 120.0f));
        boardcell.setPosition(piececoords.first, piececoords.second);
        if ((isEven(pieceyx.first) and isEven(pieceyx.second)) or (!isEven(pieceyx.first) and !isEven(pieceyx.second)))
        {
            boardcell.setFillColor(sf::Color::White);
            boardcell.setOutlineColor(sf::Color::Green);
            boardcell.setOutlineThickness(-15);
        } else
        {
            boardcell.setFillColor(sf::Color::Black);
            boardcell.setOutlineColor(sf::Color::Green);
            boardcell.setOutlineThickness(-15);
        }
        window->draw(boardcell);
        printPiece(piececoords.first + 26, piececoords.second + 26, pieceyx.first, pieceyx.second, window, thepieces[pieceyx.first][pieceyx.second].getcolor());
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
    std::vector<Pieces> piecerows;
    for (int y = 0; y < BOARD_ROWS; y++)

        for (int x = 0; x < BOARD_COLS; x++)
        {
            float cellxpos = x * cell_width;
            float cellypos = y * cell_height;

            if (y >= 0 and y <= 1)
            {
                Pieces newpiece;
                newpiece.settype(underboard[y][x]);
                newpiece.setcolor("w");
                piecerows.push_back(newpiece);
            } else if (y >= 6 and y < BOARD_ROWS)
            {
                Pieces newpiece;
                newpiece.settype(underboard[y][x]);
                newpiece.setcolor("b");
                piecerows.push_back(newpiece);
            } else
            {
                Pieces newpiece;
                newpiece.setblank(true);
                newpiece.settype(' ');
                newpiece.setcolor("");
                piecerows.push_back(newpiece);
            }
            rowcoords.emplace_back(std::make_pair(cellxpos, cellypos));
            if (x == BOARD_COLS - 1)
            {
                boardcoords.push_back(rowcoords);
                rowcoords = {};
                thepieces.push_back(piecerows);
                piecerows = {};
            }
        }
    }
}


void Chess::Game::printPiece(float spritex, float spritey, int ypos, int xpos, sf::RenderWindow* window, std::string color) {
    std::string imagedir = "C:\\Users\\rasyt\\Pictures\\Saved Pictures\\";
    sf::Texture texture;
    bool empty = false;
    imagedir += color;
    switch (thepieces[ypos][xpos].gettype())
    {
        case 'P':
            //create pawn subclass here
            imagedir += "_P60.png";
            texture.loadFromFile(imagedir);
            break;
        case 'R':
            //create rook subclass here
            imagedir += "_R60.png";
            texture.loadFromFile(imagedir);
            break;
        case 'K':
            //create knight subclass here
            imagedir += "_K60.png";
            texture.loadFromFile(imagedir);
            break;
        case 'B':
            //create bishop subclass here
            imagedir += "_b60.png";
            texture.loadFromFile(imagedir);
            break;
        case 'A':
            //create king subclass here
            imagedir += "_A60.png";
            texture.loadFromFile(imagedir);
            break;
        case 'Q':
            //create queen subclass here
            imagedir += "_Q60.png";
            texture.loadFromFile(imagedir);
            break;
        default:
            empty = true;
    }
    sf::Sprite sprite(texture);
    sprite.setPosition(spritex, spritey);
    if (!empty)
    {
        window->draw(sprite);
    }
    return;
}

//good
void Chess::Game::SetupBoard(sf::RenderWindow* window) {
    std::vector<std::pair<float, float>> rowcoords;
    std::string black = "b";
    std::string white = "w";
    std::string color;
    for (int y = 0; y < BOARD_ROWS; y++)
    {
        for (int x = 0; x < BOARD_COLS; x++)
        {
            float cellxpos = x * cell_width;
            float cellypos = y * cell_height;
            float spritex = cellxpos + (26);
            float spritey = cellypos + (26);
            sf::Texture texture;
            if (y <= 1)
            {
                color = white;
            } else
            {
                color = black;
            }
            std::unique_ptr<sf::RectangleShape> boardcell;
            boardcell = std::unique_ptr<sf::RectangleShape>(new sf::RectangleShape(sf::Vector2f(120.0f, 120.0f)));
            if (isEven(y))
            {
                if (isEven(x))
                {
                    boardcell->setFillColor(sf::Color::White);
                } else
                {
                    boardcell->setFillColor(sf::Color::Black);
                }

            } else
            {
               if (isEven(x))
               {
                   boardcell->setFillColor(sf::Color::Black);
               } else {
                   boardcell->setFillColor(sf::Color::White);
               }
            }
            boardcell->setPosition(cellxpos, cellypos);
            window->draw(*boardcell);
            printPiece(spritex, spritey, y, x, window, color);
        }
    }
}


bool Chess::Game::isEven(int number) {
    if (number % 2 == 0)
    {
        return true;
    } else
    {
        return false;
    }
}

void Chess::Game::updatepiece(int endposrow, int endposcol, char piece) {
    underboard[endposrow][endposcol] = piece;
    thepieces[endposrow][endposcol].settype(piece);
}


void Chess::Game::set_cellheight(int height) {
    cell_height = height;
}

void Chess::Game::set_cellwidth(int width) {
    cell_width = width;
}
