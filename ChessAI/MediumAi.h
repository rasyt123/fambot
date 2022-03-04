//
// Created by rasyt on 12/21/2021.
//

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
