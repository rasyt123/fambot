//
// Created by rasyt on 12/22/2021.
//
#include "Pawn.h"

//correct
void Chess::Pawn::EnactPassant(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces) {
    char temp = underboard[startposy][startposx];
    Pieces tempcopy = thepieces[startposy][startposx];
    createblank(startposy, startposx, underboard, thepieces);
    underboard[endposy][endposx] = temp;
    std::cout << "old contents: " << underboard[endposy][endposx] << std::endl;
    thepieces[endposy][endposx] = tempcopy;
}

bool Chess::Pawn::passantcheck(std::vector<std::vector<int>>& pawnmoveslist, int pawnnexty, int pawnnextx)
{
    for (auto coords : pawnmoveslist)
    {
        if (coords[2] == pawnnexty and coords[3] == pawnnextx)
        {
            pawnmoveslist.pop_back();
            return true;
        }

    }
    return false;
}

//I will check if the start pos is a pawn before I call this function in game.cpp
void Chess::Pawn::EnPassant(sf::RenderWindow* window, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string turn, bool& passant, std::vector<std::vector<int>>& pawnmovetwicewhite,
                            std::vector<std::vector<int>>& pawnmovetwiceblack) {
    if (turn == "white")
    {
        //left capture en passant with turn as white
        if (startposy == 3 and InBounds(endposy, endposx, underboard) and endposy == startposy-1 and endposx == startposx - 1
        and underboard[endposy][endposx] == ' ')
        {
            if (InBounds(startposy, startposx - 1, underboard) and thepieces[startposy][startposx - 1].getcolor() == "black" and underboard[startposy][startposx - 1] == 'P'
            and InBounds(startposy - 1, startposx - 1, underboard) and underboard[startposy - 1][startposx - 1] == ' ' and
                    InBounds(startposy - 2, startposx - 1, underboard) and passantcheck(pawnmovetwiceblack, startposy, startposx - 1))
            {
                   createblank(startposy, startposx - 1, underboard, thepieces);
                    EnactPassant(underboard, thepieces);
                    passant = true;
            }
        }
        else if (startposy == 3 and InBounds(endposy, endposx, underboard) and endposy == startposy-1 and endposx == startposx+1)
        {
            if (InBounds(startposy, startposx + 1, underboard) and thepieces[startposy][startposx + 1].getcolor() == "black" and underboard[startposy][startposx + 1] == 'P' and
            InBounds(startposy - 1, startposx + 1, underboard) and underboard[startposy - 1][startposx + 1] == ' '
            and InBounds(startposy - 2, startposx + 1, underboard) and passantcheck(pawnmovetwiceblack, startposy, startposx + 1))
            {
                createblank(startposy, startposx + 1, underboard, thepieces);
                EnactPassant(underboard, thepieces);
                passant = true;
            }
        }
    } else {
        //left capture en passant with black
        if (startposy == 4 and InBounds(endposy, endposx, underboard) and endposy == startposy + 1 and endposx == startposx - 1
        and underboard[endposy][endposx] == ' ')
        {
            if (InBounds(startposy, startposx - 1, underboard) and thepieces[startposy][startposx - 1].getcolor() == "white" and underboard[startposy][startposx - 1] == 'P' and
           underboard[endposy][endposx]  == ' ' and InBounds(startposy + 2, startposx - 1, underboard) and passantcheck(pawnmovetwicewhite, startposy, startposx - 1))
            {
                createblank(startposy, startposx - 1, underboard, thepieces);
                EnactPassant(underboard, thepieces);
                passant = true;
            }
        } else if (startposy == 4 and InBounds(endposy, endposx, underboard) and endposy == startposy + 1 and endposx == startposx + 1)
        {
            if (InBounds(startposy, startposx + 1, underboard) and thepieces[startposy][startposx + 1].getcolor() == "white" and underboard[startposy][startposx + 1] == 'P' and
            underboard[endposy][endposx] == ' ' and InBounds(startposy + 2, startposx + 1, underboard) and passantcheck(pawnmovetwicewhite, startposy, startposx + 1))
            {
                createblank(startposy, startposx + 1, underboard, thepieces);
                EnactPassant(underboard, thepieces);
                passant = true;
            }
        }
    }
}

//this is correct
void Chess::Pawn::ListPromotionOptions(sf::RenderWindow* window, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string turn, std::vector<std::vector<std::pair<float, float>>>& boardcoords, bool& promotion) {
    if (turn == "white" and IsValidMove(endposy, endposx) and endposy == 7)
    {
        std::vector<std::string> promotionstrs = {"C:\\Users\\rasyt\\Pictures\\Saved Pictures\\w_Q60.png", "C:\\Users\\rasyt\\Pictures\\Saved Pictures\\w_b60.png", "C:\\Users\\rasyt\\Pictures\\Saved Pictures\\w_R60.png","C:\\Users\\rasyt\\Pictures\\Saved Pictures\\w_K60.png"};
        std::pair<float, float> cellcoords = boardcoords[endposy][endposx];
        drawPromotions(window, promotionstrs, underboard, cellcoords);
        promotion = true;
    } else if (turn == "black" and IsValidMove(endposy, endposx) and endposy == 0)
    {
        std::vector<std::string> promotionstrs = {"C:\\Users\\rasyt\\Pictures\\Saved Pictures\\b_Q60.png", "C:\\Users\\rasyt\\Pictures\\Saved Pictures\\b_b60.png", "C:\\Users\\rasyt\\Pictures\\Saved Pictures\\b_R60.png","C:\\Users\\rasyt\\Pictures\\Saved Pictures\\b_K60.png"};
        std::pair<float, float> cellcoords = boardcoords[endposy][endposx];
        drawPromotions(window, promotionstrs, underboard, cellcoords);
        promotion = true;
    }
}

bool Chess::Pawn::lastrankoppo(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string turn,  std::vector<std::vector<std::pair<float, float>>>& boardcoords, std::pair<float, float>& promotioncoords) {
    if (turn == "white")
    {
        for (int i = 0; i < 8; i++)
        {
            if (underboard[0][i] == 'P' and thepieces[0][i].getcolor() == "white" )
            {
                promotioncoords = boardcoords[0][i];
                return true;
            }

        }
    } else if (turn == "black")
    {
        for (int i = 0; i < 8; i++)
        {
            if (underboard[7][i] == 'P' and thepieces[7][i].getcolor() == "black")
            {
                promotioncoords = boardcoords[7][i];
                return true;
            }
        }
    }
    return false;
}

//this is correct
void Chess::Pawn::drawPromotions(sf::RenderWindow* window, std::vector<std::string> promotionimgs, std::vector<std::vector<char>>& underboard, std::pair<float, float> cellcoords, float mouseposy, float mouseposx) {
    float xwidth = cellcoords.first + 26;
    for (int i = 0; i < 4; i++)
    {
        float curryheight = cellcoords.second + i * 120;
        sf::RectangleShape promotionsquare(sf::Vector2f(120.0f, 120.0f));
        promotionsquare.setPosition(cellcoords.first, curryheight);
        if ()
        {


        } else
        {



        }
        window->draw(promotionsquare);
    }
    for (int dy = 0; dy < 4; dy++)
    {
        sf::Texture piecetexture;
        piecetexture.loadFromFile(promotionimgs[dy]);
        sf::Sprite pieces(piecetexture);
        float yheight = cellcoords.second + dy * 120 + 26;
        pieces.setPosition(xwidth, yheight);
        window->draw(pieces);
    }
}


//this is correct
void Chess::Pawn::createblank(int posy, int posx, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces) {
    underboard[posy][posx] = ' ';
    thepieces[posy][posx].settype(' ');
    thepieces[posy][posx].setblank(true);
    thepieces[posy][posx].setcolor("");
}

//correct

//correct
bool Chess::Pawn::GenerateMoves(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string turn) {
    if (turn == "white")
    {
        GenerateWhite(underboard, thepieces);
        if (IsValidMove(endposy, endposx))
        {
            return true;
        } else
        {
            return false;
        }
    } else {
        GenerateBlack(underboard, thepieces);
        if (IsValidMove(endposy, endposx))
        {
            return true;
        } else {
            return false;
        }
    }
}

//correct
bool Chess::Pawn::IsValidMove(int rows, int cols) {
    for (std::pair<int, int> coordpair : possiblemoves)
    {
        if (rows == coordpair.first and cols == coordpair.second)
        {
            return true;
        }
    }
    return false;
}

//this is good

//correct
void Chess::Pawn::GenerateBlack(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces) {

    if (InBounds(startposy+1, startposx-1, underboard)) {
        watchingsquares.push_back(std::make_pair(startposy + 1, startposx - 1));
    }
    if (BottomLeft(underboard))
    {
        protectingsquares.emplace_back(std::make_pair(startposy + 1, startposx - 1));
        if (underboard[startposy + 1][startposx - 1] == 'A' and thepieces[startposy + 1][startposx - 1].getcolor() == "white")
        {
            starekingdown = true;
        } else
        {
            possiblemoves.emplace_back(std::make_pair(startposy + 1, startposx - 1));
        }
    }

    if (InBounds(startposy+1, startposx+1, underboard))
    {
        watchingsquares.push_back(std::make_pair(startposy + 1, startposx + 1));
    }

    if (BottomRight(underboard))
    {
        protectingsquares.emplace_back(std::make_pair(startposy + 1, startposx + 1));
        if (underboard[startposy + 1][startposx + 1] == 'A' and thepieces[startposy + 1][startposx + 1].getcolor() == "white")
        {
            starekingdown = true;
        } else
        {
            possiblemoves.emplace_back(std::make_pair(startposy + 1, startposx + 1));
        }
    }
    if (infrontdown(underboard))
    {
        possiblemoves.emplace_back(std::make_pair(startposy + 1, startposx));
    }
    if (infront2down(underboard))
    {
        possiblemoves.emplace_back(std::make_pair(startposy + 2, startposx));
    }
}

//correct
void Chess::Pawn::GenerateWhite(std::vector<std::vector<char>> &underboard, std::vector<std::vector<Pieces>>& thepieces) {

    if (InBounds(startposy-1, startposx-1, underboard))
    {
        watchingsquares.push_back(std::make_pair(startposy-1, startposx-1));
    }
    if (TopLeft(underboard))
    {
        protectingsquares.emplace_back(std::make_pair(startposy - 1, startposx - 1));
        if (underboard[startposy - 1][startposx - 1] == 'A' and thepieces[startposy - 1][startposx - 1].getcolor() == "black")
        {
            starekingdown = true;
        } else
        {
            possiblemoves.emplace_back(std::make_pair(startposy-1, startposx-1));
        }
    }

    if (InBounds(startposy-1, startposx + 1, underboard))
    {
        watchingsquares.push_back(std::make_pair(startposy-1, startposx+1));
    }

    if (TopRight(underboard))
    {
        protectingsquares.emplace_back(std::make_pair(startposy - 1, startposx + 1));
        if (underboard[startposy - 1][startposx + 1] == 'A' and thepieces[startposy - 1][startposx + 1].getcolor() == "black")
        {
            starekingdown = true;
        } else
        {
            possiblemoves.emplace_back(std::make_pair(startposy-1, startposx+1));
        }
    }

    if (infronttop(underboard))
    {
        possiblemoves.emplace_back(std::make_pair(startposy-1, startposx));
    }
    if (infront2top(underboard))
    {
        possiblemoves.emplace_back(std::make_pair(startposy-2, startposx));
    }
}

//correct
bool Chess::Pawn::BottomLeft(std::vector<std::vector<char>>& underboard) {
    return InBounds(startposy+1, startposx-1, underboard) and underboard[startposy + 1][startposx - 1] != ' ' ;
}

//correct
bool Chess::Pawn::BottomRight(std::vector<std::vector<char>>& underboard) {
    return InBounds(startposy+1, startposx+1, underboard) and underboard[startposy + 1][startposx + 1] != ' ';
}

//correct
bool Chess::Pawn::infrontdown(std::vector<std::vector<char>> &underboard) {
    return InBounds(startposy+1, startposx, underboard) and underboard[startposy + 1][startposx] == ' ';
}

//correct
bool Chess::Pawn::infront2down(std::vector<std::vector<char>> &underboard) {
    return startposy == 1 and InBounds(startposy+2, startposx, underboard) and underboard[startposy + 2][startposx] == ' ';
}

//correct
bool Chess::Pawn::TopLeft(std::vector<std::vector<char>> &underboard) {
    return InBounds(startposy-1, startposx-1, underboard) and underboard[startposy - 1][startposx - 1] != ' ';
}

//correct
bool Chess::Pawn::TopRight(std::vector<std::vector<char>> &underboard) {
    return InBounds(startposy-1, startposx + 1, underboard) and underboard[startposy - 1][startposx + 1] != ' ';
}

//correct
bool Chess::Pawn::infronttop(std::vector<std::vector<char>> &underboard) {
    return InBounds(startposy-1, startposx, underboard) and underboard[startposy - 1][startposx] == ' ';
}


//correct
bool Chess::Pawn::infront2top(std::vector<std::vector<char>> &underboard) {
    return startposy == 6 and InBounds(startposy-2, startposx, underboard) and underboard[startposy - 2][startposx] == ' ';
}


std::vector<std::pair<int,int>> Chess::Pawn::getpossiblemoves() {
    return possiblemoves;
}


std::vector<std::pair<int, int>> Chess::Pawn::getpossiblemovescpy() {
    return possiblemovescpy;
}

std::vector<std::pair<int, int>> Chess::Pawn::getwatchingsquares() {
    return watchingsquares;
}

bool Chess::Pawn::getstaredown() {
    return starekingdown;
}




