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
    bool promotion = false;
    std::pair<float, float> startpiececoords;
    std::pair<int, int> startpieceyx;
    startpieceyx.first = OUT_OF_BOUNDS;
    startpieceyx.second = OUT_OF_BOUNDS;
    startpiececoords.first = OUT_OF_BOUNDS;
    startpiececoords.second = OUT_OF_BOUNDS;
    std::string turncolor = "white";
    addcoords();
    float clickposy = OUT_OF_BOUNDS;
    float clickposx = OUT_OF_BOUNDS;
    int prevy = OUT_OF_BOUNDS;
    int prevx = OUT_OF_BOUNDS;
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
        CheckSelect(&window, isgreen, startpiececoords, startpieceyx, mademove, clickposy, clickposx);
        std::pair<int, int> endpieceyx = returnendpos(&window, currentturn);
        MakeMovePlayer(&window, currentturn, startpieceyx, endpieceyx, )
        window.display();
        if (mademove)
        {
            currturncount += 1;
        }
    }
}

bool Chess::Game::MakeMovePlayer(sf::RenderWindow *window, std::string colorturn, std::pair<int, int> startpieceyx, std::pair<int, int> endpieceyx, bool& mademove, bool& checkmate, int prevy, int prevx, Player& currentplayer) {
    bool passant = false;
    bool moveexists = false;
    bool random = false;
    int startposy = startpieceyx.first;
    int startposx = startpieceyx.second;
    int endposy = endpieceyx.first;
    int endposx = endpieceyx.second;
    Pawn pawnobj(startposx, startposy, endposx, endposy);
    Rook rookobj(startposx, startposy, endposx, endposy);
    Knight knightobj(startposx, startposy, endposx, endposy);
    Bishop bishopobj(startposx, startposy, endposx, endposy);
    Queen queenobj(startposx, startposy, endposx, endposy);
    std::pair<int, int> kingcoords = findking(colorturn, this->underboard, this->thepieces);
    std::pair<float, float> cellkingcoords = boardcoords[kingcoords.first][kingcoords.second];
    King kingobj(kingcoords.second, kingcoords.first, endpieceyx.second, endpieceyx.first);
    if (kingobj.determinecheck(this->underboard, this->thepieces, colorturn))
    {
        window->clear();
        SetupBoard(window);
        kingobj.clearpossiblemoves();
        kingobj.generatemoves(this->underboard, this->thepieces, colorturn);
        float ycellkingcoord = cellkingcoords.second + 26;
        float xcellkingcoord = cellkingcoords.first + 26;
        CoverCellGreen(window, random, cellkingcoords, kingcoords, ycellkingcoord, xcellkingcoord);
        std::pair<int,int> result = returnendpos(window, colorturn);
        if (result.first == OUT_OF_BOUNDS and result.second == OUT_OF_BOUNDS)
        {
            mademove = false;
        } else if (IsValidMove(result.first, result.second, kingobj.getpossiblemoves())) {
            move(this->underboard, this->thepieces, colorturn, kingcoords.first, kingcoords.second, result.first, result.second, currentplayer);
            mademove = true;
            return true;
        }
        return false;
    }
    if (kingobj.determinecheckmate(this->underboard, this->thepieces, colorturn)) {
        checkmate = true;
    }
    switch (underboard[startposy][startposx])
    {
        case 'P':
            pawnobj.GenerateMoves(this->underboard, this->thepieces, colorturn);
            pawnobj.EnPassant(window, this->underboard, this->thepieces, colorturn, thepieces[prevy][prevx], prevy, prevx, passant);
            if (passant) {
                pawnobj.EnactPassant(this->underboard, this->thepieces);
                break;
            }
            if (IsValidMove(endposy, endposx, pawnobj.getpossiblemoves()))
            {
                //sf::RenderWindow* window, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string turn, std::vector<std::vector<std::pair<float, float>>>& boardcoord
                pawnobj.ListPromotionOptions(window, this->underboard, this->thepieces, colorturn, this->boardcoords);
                move(this->underboard, this->thepieces, colorturn, startposy, startposx, endposy, endposx, currentplayer);
                mademove = true;
                return true;
            }
            break;
        case 'R':
            rookobj.GenerateMoves(this->underboard, this->thepieces, colorturn);
            if (IsValidMove(endposy, endposx, rookobj.getpossiblemoves()))
            {
                move(this->underboard, this->thepieces, colorturn, startposy, startposx, endposy, endposx, currentplayer);
                mademove = true;
                return true;
            }
            break;
        case 'K':
            knightobj.GenerateMoves(this->underboard, this->thepieces, colorturn);
            if (IsValidMove(endposy, endposx, knightobj.getpossiblemoves()))
            {
                move(this->underboard, this->thepieces, colorturn, startposy, startposx, endposy, endposx,
                     currentplayer);
                mademove = true;
                return true;
            }
            break;
        case 'B':
            bishopobj.GenerateMoves(this->underboard, this->thepieces, colorturn);
            if (IsValidMove(endposy, endposx, bishopobj.getpossiblemoves()))
            {
                move(this->underboard, this->thepieces, colorturn, startposy, startposx, endposy, endposx, currentplayer);
                mademove = true;
                return true;
            }
            break;
        case 'Q':
            queenobj.GenerateMoves(this->underboard, this->thepieces, colorturn);
            if (IsValidMove(endposy, endposx, queenobj.getpossiblemoves()))
            {
                move(this->underboard, this->thepieces, colorturn, startposy, startposx, endposy, endposx, currentplayer);
                mademove = true;
                return true;
            }
            break;
        case 'A':
            kingobj.GenerateMoves(this->underboard, this->thepieces, colorturn);
            if (IsValidMove(endposy, endposx, kingobj.getpossiblemoves()))
            {
                move(this->underboard, this->thepieces, colorturn, startposy, startposx, endposy, endposx, currentplayer);
                mademove = true;
                return true;
            } else if (kingobj.performCastle(this->underboard, this->thepieces, colorturn))
            {
                mademove = true;
                return true;
            }
        default:
            break;
    }
    return false;
}



std::pair<int, int> Chess::Game::findking(std::string color, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces) {
    for (int height = 0; height < BOARD_ROWS; height++)
    {
        for (int width = 0; width < BOARD_COLS; width++)
        {
           if (underboard[height][width] == 'A' and thepieces[height][width].getcolor() == color)
           {
               std::pair<int, int> kingcoords = std::make_pair(height,width);
               return kingcoords;
           }
        }
    }
    return {};
}



void Chess::Game::move(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string turn, int startposy, int startposx, int endposy, int endposx, Player& currentplayer) {
    char oldpiece = underboard[startposy][startposx];
    underboard[startposy][startposx] = ' ';
    switch (underboard[endposy][endposx])
    {
        case 'P':
            currentplayer.addpoints(1);
            break;
        case 'R':
            currentplayer.addpoints(5);
            break;
        case 'K':
            currentplayer.addpoints(3);
            break;
        case 'B':
            currentplayer.addpoints(3);
            break;
        case 'Q':
            currentplayer.addpoints(9);
            break;
        default:
            break;
    }
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


std::pair<int,int> Chess::Game::returnendpos(sf::RenderWindow* window, std::string color) {
    sf::Event event;
    int clickposy;
    int clickposx;
    std::pair<float, float> piececoords;
    std::pair<int, int> pieceyx;
    int startposy;
    int startposx;
    while (window->pollEvent(event)) {
        if (event.type == sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
            clickposy = mousePos.y;
            clickposx = mousePos.x;
            for (int height = 0; height < BOARD_ROWS; height++) {
                for (int width = 0; width < BOARD_COLS; width++) {
                    float cellxpos = width * cell_width;
                    float cellypos = height * cell_height;
                    if (clickposx > cellxpos and clickposx < cellxpos + (float) cell_width and clickposy > cellypos and
                        clickposy < cellypos + (float) cell_height) {
                        if (underboard[height][width] != ' ' and thepieces[height][width].getcolor() != color) {
                            piececoords = boardcoords[height][width];
                            pieceyx = std::make_pair(height, width);
                            return pieceyx;
                        }
                    }
                }
            }
            break;
        }
    }
    return {OUT_OF_BOUNDS, OUT_OF_BOUNDS};
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
    sf::Color green(118, 150, 86);
    sf::Color palewhite(238, 238, 210);
    if (isPiece(clickposy, clickposx, piececoords, pieceyx) and piececoords.first != -9000 and piececoords.second != -9000
    and thepieces[pieceyx.first][pieceyx.second].getcolor() == currentturn)
    {
        sf::RectangleShape boardcell(sf::Vector2f(120.0f, 120.0f));
        boardcell.setPosition(piececoords.first, piececoords.second);
        if ((isEven(pieceyx.first) and isEven(pieceyx.second)) or (!isEven(pieceyx.first) and !isEven(pieceyx.second)))
        {
            boardcell.setFillColor(palewhite);
            boardcell.setOutlineColor(sf::Color::Green);
            boardcell.setOutlineThickness(-15);
        } else
        {
            boardcell.setFillColor(green);
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
                newpiece.setcolor("b");
                piecerows.push_back(newpiece);
            } else if (y >= 6 and y < BOARD_ROWS)
            {
                Pieces newpiece;
                newpiece.settype(underboard[y][x]);
                newpiece.setcolor("w");
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
    sf::Color green(118, 150, 86);
    sf::Color palewhite(238, 238, 210);
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
                color = black;
            } else
            {
                color = white;
            }
            std::unique_ptr<sf::RectangleShape> boardcell;
            boardcell = std::unique_ptr<sf::RectangleShape>(new sf::RectangleShape(sf::Vector2f(120.0f, 120.0f)));
            if (isEven(y))
            {
                if (isEven(x))
                {
                    boardcell->setFillColor(palewhite);
                } else
                {
                    boardcell->setFillColor(green);
                }

            } else
            {
               if (isEven(x))
               {
                   boardcell->setFillColor(green);
               } else {
                   boardcell->setFillColor(palewhite);
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


bool Chess::Game::IsValidMove(int row, int col, std::vector<std::pair<int, int>> possiblemoves) {
    for (std::pair<int, int> coordpair : possiblemoves)
    {
        if (row == coordpair.first and col == coordpair.second)
        {
            return true;
        }
    }
    return false;
}
