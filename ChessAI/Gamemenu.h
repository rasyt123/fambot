//
// Created by rasyt on 2/7/2022.
//

#ifndef CHESS_GAMEMENU_H
#define CHESS_GAMEMENU_H
#include "Game.h"


namespace Chess {
    class Gamemenu {


    public:

        void addfonts(sf::RenderWindow *window);
        bool loadgamemenu(sf::RenderWindow *window);

        bool playbuttonpressed(float posx, float posy);
        bool quitbuttonpressed(float posx, float posy);
        bool optionsbuttonpressed(float posx, float posy);
        void windowpoller(sf::RenderWindow *window);
        void checkmatemenu(sf::RenderWindow *window);



    private:
        std::vector<std::pair<int,int>> menubarcoords;






    };
}

#endif //CHESS_GAMEMENU_H
