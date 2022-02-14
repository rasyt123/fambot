//
// Created by rasyt on 2/7/2022.
//

#include "Gamemenu.h"



void Chess::Gamemenu::loadgamemenu()
{
    sf::RenderWindow window(sf::VideoMode(960, 960), "Chess", sf::Style::Close | sf::Style::Titlebar);
    sf::Texture background;
    sf::Sprite backsprite;
    background.loadFromFile("C:\\Users\\rasyt\\Pictures\\Saved Pictures\\chessui.png");
    backsprite.setTexture(background);
    backsprite.setScale(960/1200, 960/800);

    sf::RectangleShape PlayButton(sf::Vector2f(420.0f, 250.0f));
    PlayButton.setFillColor(sf::Color(255, 255, 255));

    sf::RectangleShape OptionsButton(sf::Vector2f(420.0f, 250.0f));
    OptionsButton.setFillColor(sf::Color(255, 255, 255));

    sf::RectangleShape Quitbutton(sf::Vector2f(420.0f, 250.0f));
    Quitbutton.setFillColor(sf::Color(255, 255, 255));

    PlayButton.setPosition();
    OptionsButton.setPosition();
    Quitbutton.setPosition();



}
