//
// Created by rasyt on 12/20/2021.
//

#ifndef CHESS_PLAYER_H
#define CHESS_PLAYER_H
#include "Pieces.h"
namespace Chess {
    class Player {
    public:
        void addpoints(int val);


    private:
        int totalpoints = 0;
        int numpiecescount = 0;
        std::string color;
        std::vector<char> capturedpieces2;
        std::vector<Pieces> capturedpieces;

    };

}



#endif //CHESS_PLAYER_H
