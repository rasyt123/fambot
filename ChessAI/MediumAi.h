//
// Created by rasyt on 12/21/2021.
//
#include "King.h"
#include "Pawn.h"
#include "Rook.h"
#include "Queen.h"
#include "Knight.h"
#include "Pieces.h"
#include "Player.h"
#ifndef CHESS_MEDIUMAI_H
#define CHESS_MEDIUMAI_H

#include <vector>

namespace Chess {
    class MediumAi {



    public:
        void setPawnevalsquares();
        void setKnightevalsquares();
        void setBishopevalsquares();
        void setRookevalsquares();
        void setQueenevalsquares();
        void setKingevalsquares();
        std::vector<std::pair<char, std::vector<int>>> getallpossiblemoves(std::string color, std::vector<std::vector<char>> underboard,
        std::vector<std::vector<Pieces>> thepieces);




    private:
        //Eval Function
        //Square Piece Tables
        std::vector<std::vector<int>> pawnevalsquares;
        std::vector<std::vector<int>> knightevalsquares;
        std::vector<std::vector<int>> bishopevalsquares;
        std::vector<std::vector<int>> rookevalsquares;
        std::vector<std::vector<int>> queenevalsquares;
        std::vector<std::vector<int>> kingevalsquares;









    };






}


#endif //CHESS_MEDIUMAI_H
