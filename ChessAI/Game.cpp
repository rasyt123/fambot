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


bool Chess::Game::isPiece2(float y, float x, std::pair<int, int>& boardcords) {
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
                    boardcords = std::make_pair(height, width);
                    return true;
                }
            }
        }
    }
    return false;
}


bool Chess::Game::samecoords(float curry, float currx, float comparisony, float comparisonx) {
    for (int height = 0; height < BOARD_ROWS; height++)
    {
        for (int width = 0; width < BOARD_COLS; width++)
        {
            float cellxpos = width * cell_width;
            float cellypos = height * cell_height;
            if (currx > cellxpos and currx < cellxpos + (float) cell_width and curry > cellypos and curry < cellypos + (float) cell_height
            and comparisonx > cellxpos and comparisonx < cellxpos + (float) cell_width and comparisony > cellypos and comparisony < cellypos + (float) cell_height)
            {
                if (underboard[height][width] != ' ')
                {
                    return true;
                }
            }
        }
    }
    return false;
}


void Chess::Game::menudeal(sf::RenderWindow *window, bool& easyaistartgame, bool& mediumaistartgame, bool& humanstartgame, Gamemenu& zegame) {
        window->clear();
        sf::Vector2i mousePosmenu = sf::Mouse::getPosition(*window);
        float currmouseposy = mousePosmenu.y;
        float currmouseposx = mousePosmenu.x;
        if (zegame.loadgamemenu(window,currmouseposx, currmouseposy) and !zegame.getplaybutton())
        {
            zegame.parseclicks(window);
        } else if (zegame.getplaybutton())
        {
            zegame.loadplaymenu(window, currmouseposx, currmouseposy);
            zegame.parseclicks2(window);
            if (zegame.geteasyai()) {
                easyaistartgame = true;
            } else if (zegame.getmediumai())
            {
                mediumaistartgame = true;
            } else if (zegame.gethumanopponent())
            {
                humanstartgame = true;
            }
        }
        window->display();
        return;
}


//make gameloop pass a pointer to the sfrenderwindow
void Chess::Game::GameLoop() {
    sf::RenderWindow window(sf::VideoMode(960, 960), "Chess", sf::Style::Close | sf::Style::Titlebar);
    bool incheck = false;
    bool tileselect = false;
    bool isgreen = false;
    bool mademove = false;
    bool promotion = false;
    bool move = false;
    bool ischeckmate = false;
    std::vector<std::vector<char>> copyboardstate;
    std::vector<std::vector<Pieces>> copyboard;
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
    Pieces prevpiece;
    std::pair<int, int> endpieceyx;
    Player Player1; //white
    Player Player2; //black
    Player currplayer;
    bool movemade;
    Pawn pawn;
    int currentendposy = OUT_OF_BOUNDS;
    int currentendposx = OUT_OF_BOUNDS;
    bool promotionmove = false;
    //For en passant, I need to know that the pawn im about to en passant
    //previously moved two spaces from its original square
    //keep track of the previous board state
    bool button = false;
    Gamemenu zegame;
    bool easyaistart = false;
    bool mediumaistart = false;
    bool humanopp = false;
    bool thecheckmate = false;
    std::string checkmateturn;
    while (window.isOpen())
    {
        if (ischeckmate)
        {
            window.clear();
            zegame.checkmatemenu(&window, checkmateturn);
            window.display();
            continue;
        }
        if (easyaistart or mediumaistart or humanopp)
        {
        } else {
            menudeal(&window, easyaistart, mediumaistart, humanopp, zegame);
            continue;
        }
        if (isEven(currturncount))
        {
            currentturn = "white";
            currplayer = Player1;
        } else
        {
            currentturn = "black";
            currplayer = Player2;
        }
        sf::Event event;
        window.clear();
        SetupBoard(&window);
        while (window.pollEvent(event))
        {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        sf::Vector2i mousePos1 = sf::Mouse::getPosition(window);
                        int getposy = mousePos1.y;
                        int getposx = mousePos1.x;
                        std::pair<int, int> curryxpair;
                        bool confirmedpiece = isPiece2(getposy, getposx, curryxpair);
                        if (promotion)
                        {
                            HighlightPromotion(&window, pawn, currentendposy, currentendposx, currentturn, promotionmove);
                        } else if (!tileselect or (confirmedpiece and thepieces[curryxpair.first][curryxpair.second].getcolor() == currentturn))
                        {
                            std::cout << "Tileselcted!" << std::endl;
                            sf::Vector2i mousePos1 = sf::Mouse::getPosition(window);
                            clickposy = mousePos1.y;
                            clickposx = mousePos1.x;
                            CheckSelect(&window, isgreen, startpiececoords, startpieceyx, mademove, clickposy, clickposx);
                            if (Chess::Game::checkmate(currentturn, endpieceyx.first, endpieceyx.second))
                            {
                                std::cout << "Checkmated" << std::endl;
                                checkmateturn = currentturn;
                                ischeckmate = true;
                                break;
                            }
                            else if (currentlyincheck(&window, currentturn, mademove, endpieceyx.first, endpieceyx.second, currplayer))
                            {
                                std::cout << "Check but not checkmate" << std::endl;
                                incheck = true;
                                startpieceyx = findking(currentturn, this->underboard, this->thepieces);
                            }
                            tileselect = true;
                            move = true;
                        } else if (tileselect and move and !samecoords(startpiececoords.first, startpiececoords.second, getposy, getposx))
                        {
                            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                            int clickposy1 = mousePos.y;
                            int clickposx1 = mousePos.x;
                            endpieceyx = returnendpos(&window, currentturn, clickposy1, clickposx1);
                            currentendposy = endpieceyx.first;
                            currentendposx = endpieceyx.second;
                            std::cout << "Value of incheck: " << incheck << std::endl;
                            //Deal with moving a piece that makes the king go in check
                            //
                            if (incheck)
                            {
                                std::cout << "I'm in check bruh!" << std::endl;
                                copyboardstate = underboard;
                                copyboard = thepieces;
                                MakeMovePlayer(&window, currentturn, startpieceyx, endpieceyx,currplayer, promotion);
                                if (currentlyincheck(&window, currentturn, mademove, endpieceyx.first, endpieceyx.second, currplayer))
                                {
                                    std::cout << "current turn: " << currentturn;
                                    underboard = copyboardstate;
                                    thepieces = copyboard;
                                    tileselect = false;
                                } else
                                {
                                    std::cout << "Got out of check!" << std::endl;
                                    move = false;
                                    tileselect = false;
                                    incheck = false;
                                    currturncount += 1;
                                }
                                break;
                            }
                            if (MakeMovePlayer(&window, currentturn, startpieceyx, endpieceyx,currplayer, promotion))
                            {
                                tileselect = false;
                                move = false;
                                currturncount += 1;
                            }
                        }
                    }
                    break;
            }
        }
        if (move and !ischeckmate)
        {
            CheckSelect(&window, isgreen, startpiececoords, startpieceyx, mademove, clickposy, clickposx);
        }
        window.display();
        /*
        if (ischeckmate) {
            std::cout << "End Game!" << std::endl;
            break;
        }
         */
    }
    std::cout << "End Game!" << std::endl;
}

bool Chess::Game::currentlyincheck(sf::RenderWindow *window, std::string colorturn, bool& mademove, int endposy, int endposx, Player currentplayer)
{
    std::pair<int, int> kingcoords = findking(colorturn, this->underboard, this->thepieces);
    King kingobj(kingcoords.second, kingcoords.first, endposx, endposy);
    if (kingobj.determinecheck(this->underboard, this->thepieces, colorturn))
    {
        std::cout << "I am definitely in check!" << std::endl;
        return true;
    } else
    {
        std::cout << "Check wrong!" << std::endl;
        return false;
    }
}



bool Chess::Game::checkmate(std::string colorturn, int endposy, int endposx) {
    std::cout << "Did I get pass this checkmate function? " << std::endl;
    std::pair<int, int> kingcoords = findking(colorturn, this->underboard, this->thepieces);
    std::pair<float, float> cellkingcoords = boardcoords[kingcoords.first][kingcoords.second];
    King kingobj(kingcoords.second, kingcoords.first, endposx, endposy);
    if (kingobj.determinecheckmate(this->underboard, this->thepieces, colorturn)) {
        std::cout << "Finished the checkmate!" << std::endl;
        return true;
    }
    return false;
}

bool Chess::Game::checkpawnmovetwice(int startposy, int startposx, int endposy, int endposx, std::string turn, Pawn pawnobj) {
        if (turn == "white")
        {
            for (auto item : pawnobj.getpossiblemoves())
            {
                if (endposy == startposy - 2 and endposx == startposx and item.first == endposy and item.second == endposx)
                {
                   std::vector<int> savepos = {startposy, startposx, item.first, item.second};
                   std::string currinfo = turn;
                   pawnmovetwicewhite.push_back(savepos);
                   pawninformationwhite.push_back(currinfo);
                   return true;
                }
            }
        } else if (turn == "black")
        {
            for (auto item : pawnobj.getpossiblemoves())
            {
                if (endposy == startposy + 2 and endposx == startposx and item.first == endposy and item.second == endposx)
                {
                    std::vector<int> savepos = {startposy, startposx, item.first, item.second};
                    std::string currinfo = turn;
                    pawnmovetwiceblack.push_back(savepos);
                    pawninformationblack.push_back(currinfo);
                    return true;
                }
            }
        }
        return false;
}


bool Chess::Game::MakeMovePlayer(sf::RenderWindow *window, std::string colorturn, std::pair<int, int> startpieceyx, std::pair<int, int> endpieceyx, Player& currentplayer, bool& promotion) {
    bool passant = false;
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
    King kingobj(kingcoords.second, kingcoords.first, endposx, endposy);
    switch (underboard[startposy][startposx])
    {
        case 'P':
            pawnobj.GenerateMoves(this->underboard, this->thepieces, colorturn);
            checkpawnmovetwice(startposy, startposx, endposy, endposx, colorturn, pawnobj);
            pawnobj.EnPassant(window, this->underboard, this->thepieces, colorturn, passant, pawnmovetwicewhite, pawnmovetwiceblack);
            if (passant)
            {
                return true;
            }
            if (IsValidMove(endposy, endposx, pawnobj.getpossiblemoves()))
            {
                //sf::RenderWindow* window, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string turn, std::vector<std::vector<std::pair<float, float>>>& boardcoord
                pawnobj.ListPromotionOptions(window, this->underboard, this->thepieces, colorturn, this->boardcoords, promotion);
                move(this->underboard, this->thepieces, colorturn, startposy, startposx, endposy, endposx, currentplayer);
                return true;
            }
            break;
        case 'R':
            rookobj.GenerateMoves(this->underboard, this->thepieces, colorturn);
            if (IsValidMove(endposy, endposx, rookobj.getpossiblemoves()))
            {
                move(this->underboard, this->thepieces, colorturn, startposy, startposx, endposy, endposx, currentplayer);
                return true;
            }
            break;
        case 'K':
            knightobj.GenerateMoves(this->underboard, this->thepieces, colorturn);
            if (IsValidMove(endposy, endposx, knightobj.getpossiblemoves()))
            {
                move(this->underboard, this->thepieces, colorturn, startposy, startposx, endposy, endposx,
                     currentplayer);

                return true;
            }
            break;
        case 'B':
            bishopobj.GenerateMoves(this->underboard, this->thepieces, colorturn);
            if (IsValidMove(endposy, endposx, bishopobj.getpossiblemoves()))
            {
                move(this->underboard, this->thepieces, colorturn, startposy, startposx, endposy, endposx, currentplayer);
                return true;
            }
            break;
        case 'Q':
            queenobj.GenerateMoves(this->underboard, this->thepieces, colorturn);
            if (IsValidMove(endposy, endposx, queenobj.getpossiblemoves()))
            {
                move(this->underboard, this->thepieces, colorturn, startposy, startposx, endposy, endposx, currentplayer);
                return true;
            }
            break;
        case 'A':
            kingobj.GenerateMoves(this->underboard, this->thepieces, colorturn);
            if (IsValidMove(endposy, endposx, kingobj.getpossiblemoves()))
            {
                move(this->underboard, this->thepieces, colorturn, startposy, startposx, endposy, endposx, currentplayer);
                return true;
            } else if (kingobj.performCastle(this->underboard, this->thepieces, colorturn))
            {
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

std::pair<int,int> Chess::Game::returnendpos(sf::RenderWindow* window, std::string color, int clickposy, int clickposx) {
    sf::Event event;
    std::pair<float, float> piececoords;
    std::pair<int, int> pieceyx;
    int startposy;
    int startposx;
    for (int height = 0; height < BOARD_ROWS; height++) {
        for (int width = 0; width < BOARD_COLS; width++) {
                float cellxpos = width * cell_width;
                float cellypos = height * cell_height;
                if (clickposx > cellxpos and clickposx < cellxpos + (float) cell_width and clickposy > cellypos and
                            clickposy < cellypos + (float) cell_height) {
                            std::cout << "END POS FOUND" << std::endl;
                            piececoords = boardcoords[height][width];
                            pieceyx = std::make_pair(height, width);
                            return pieceyx;
                    }
                }
         }
    return {OUT_OF_BOUNDS, OUT_OF_BOUNDS};
}


void Chess::Game::CheckSelect(sf::RenderWindow* window, bool& isgreen,  std::pair<float, float>& piececoords, std::pair<int, int>& pieceyx, bool mademove, float& clickposy, float& clickposx) {
    if (isPiece((float) clickposy, (float)clickposx, piececoords, pieceyx) and piececoords.first != -9000 and piececoords.second != -9000)
        {
            if (thepieces[pieceyx.first][pieceyx.second].getcolor() == currentturn)
            {
                CoverCellGreen(window, isgreen, piececoords, pieceyx, clickposy, clickposx);
            }
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
    {
        for (int x = 0; x < BOARD_COLS; x++)
        {
            float cellxpos = x * cell_width;
            float cellypos = y * cell_height;

            if (y >= 0 and y <= 1)
            {
                Pieces newpiece;
                newpiece.settype(underboard[y][x]);
                newpiece.setcolor("black");
                piecerows.push_back(newpiece);
            } else if (y >= 6 and y < BOARD_ROWS)
            {
                Pieces newpiece;
                newpiece.settype(underboard[y][x]);
                newpiece.setcolor("white");
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
    if (color == "white") {
        color = "w";
    } else if (color == "black") {
        color = "b";
    }
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
            color = thepieces[y][x].getcolor();
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
