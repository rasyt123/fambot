//
// Created by rasyt on 12/21/2021.
//

#include "MediumAi.h"



void Chess::MediumAi::setPawnevalsquares() {
    pawnevalsquares = {{0,  0,  0,  0,  0,  0,  0,  0},
                       {50, 50, 50, 50, 50, 50, 50, 50},
                       {10, 10, 20, 30, 30, 20, 10, 10},
                       {5,  5, 10, 25, 25, 10,  5,  5},
                       {0,  0,  0, 20, 20,  0,  0,  0},
                       {5, -5,-10,  0,  0,-10, -5,  5},
                       {5, 10, 10,-20,-20, 10, 10,  5},
                       {0,  0,  0,  0,  0,  0,  0,  0}};
};



void Chess::MediumAi::setKnightevalsquares() {
    knightevalsquares = {{-50,-40,-30,-30,-30,-30,-40,-50},
                         {-40,-20,  0,  0,  0,  0,-20,-40},
                         {-30,  0, 10, 15, 15, 10,  0,-30},
                         {-30,  5, 15, 20, 20, 15,  5,-30},
                         {-30,  0, 15, 20, 20, 15,  0,-30},
                         {-30,  5, 10, 15, 15, 10,  5,-30},
                         {-40,-20,  0,  5,  5,  0,-20,-40},
                         {-50,-40,-30,-30,-30,-30,-40,-50}};
}


void Chess::MediumAi::setBishopevalsquares() {
    bishopevalsquares = {{-20,-10,-10,-10,-10,-10,-10,-20},
                         {-10,  0,  0,  0,  0,  0,  0,-10},
                         {-10,  0,  5, 10, 10,  5,  0,-10},
                         {-10,  5,  5, 10, 10,  5,  5,-10},
                         {-10,  0, 10, 10, 10, 10,  0,-10},
                         {-10, 10, 10, 10, 10, 10, 10,-10},
                         {-10,  5,  0,  0,  0,  0,  5,-10},
                         {-20,-10,-10,-10,-10,-10,-10,-20}};
}



void Chess::MediumAi::setRookevalsquares() {
    rookevalsquares = {{0,  0,  0,  0,  0,  0,  0,  0},
                       {5, 10, 10, 10, 10, 10, 10,  5},
                       {-5,  0,  0,  0,  0,  0,  0, -5},
                       {-5,  0,  0,  0,  0,  0,  0, -5},
                       {-5,  0,  0,  0,  0,  0,  0, -5},
                       {-5,  0,  0,  0,  0,  0,  0, -5},
                       {-5,  0,  0,  0,  0,  0,  0, -5},
                       {0,  0,  0,  5,  5,  0,  0,  0}};
}


void Chess::MediumAi::setQueenevalsquares() {
    queenevalsquares = {{-20,-10,-10, -5, -5,-10,-10,-20},
            {-10,  0,  0,  0,  0,  0,  0,-10},
            {-10,  0,  5,  5,  5,  5,  0,-10},
            {-5,  0,  5,  5,  5,  5,  0, -5},
            {0,  0,  5,  5,  5,  5,  0, -5},
            {-10,  5,  5,  5,  5,  5,  0,-10},
            {-10,  0,  5,  0,  0,  0,  0,-10},
            {-20,-10,-10, -5, -5,-10,-10,-20}};
}


void Chess::MediumAi::setKingevalsquares() {
    kingevalsquares = {{-50,-40,-30,-20,-20,-30,-40,-50},
                       {-30,-20,-10,  0,  0,-10,-20,-30},
                       {-30,-10, 20, 30, 30, 20,-10,-30},
                       {-30,-10, 30, 40, 40, 30,-10,-30},
                       {-30,-10, 30, 40, 40, 30,-10,-30},
                       {-30,-10, 20, 30, 30, 20,-10,-30},
                       {-30,-30,  0,  0,  0,  0,-30,-30},
                       {-50,-30,-30,-30,-30,-30,-30,-50}};
}



std::vector<std::pair<char, std::vector<int>>> Chess::MediumAi::getallpossiblemoves(std::string color, std::vector<std::vector<char>> underboard, std::vector<std::vector<Pieces>> thepieces) {
        std::vector<std::pair<char, std::vector<int>>> allpossiblemoves;
        /*
         *
         * Pawn pawnobj(startposx, startposy, endposx, endposy);
    Rook rookobj(startposx, startposy, endposx, endposy);
    Knight knightobj(startposx, startposy, endposx, endposy);
    Bishop bishopobj(startposx, startposy, endposx, endposy);
    Queen queenobj(startposx, startposy, endposx, endposy);
         *
         *
         *
         *
         *
         *
         */
    Pawn pawnobj(0, 0, -9000, -9000);
    Rook rookobj(0, 0, -9000, -9000);
    //special moves I need to add: 
    //castling, en passant, promotion

    Knight knightobj(i, j, -9000, -9000);

        for (int i = 0; i < underboard.size(); i++)
        {
            for (int j = 0; j < underboard[0].size(); i++)
            {
                if (thepieces[i][j].getcolor() == color)
                {
                    switch (underboard[i][j])
                    {
                        case 'P':



                            break;
                        case 'R':


                            break;
                        case 'K':

                            break;
                        case 'B':

                            break;
                        case 'Q':

                            break;
                        case 'A':


                            break;



                    }
                }
            }
        }



}


