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
        void addmenu2fonts(sf::RenderWindow *window, std::string topbuttonstr, std::string midbuttonstr, std::string bottomstr);
        bool loadgamemenu(sf::RenderWindow *window, float highlightx, float highlighty);
        void loadplaymenu(sf::RenderWindow *window, float highlightx, float highlighty);

        bool highlightplay(float posx, float posy);
        bool highlightquit(float posx, float posy);
        bool highlightoptions(float posx, float posy);
        void windowpoller(sf::RenderWindow *window);
        void checkmatemenu(sf::RenderWindow *window);
        void parseclicks(sf::RenderWindow *window);
        void parseclicks2(sf::RenderWindow *window);

        void createbuttons(sf::RenderWindow *window, float highlightx, float highlighty);
        void checkmatemenu(sf::RenderWindow *window, std::string color);


        bool geteasyai();
        bool getmediumai();
        bool gethumanopponent();
        bool getplaybutton();



    private:
        std::vector<std::pair<int,int>> menubarcoords;
        bool easyai = false;
        bool mediumai = false;
        bool humanopponent = false;
        bool playbutton = false;
        bool checkmate = false;






    };
}

#endif //CHESS_GAMEMENU_H


