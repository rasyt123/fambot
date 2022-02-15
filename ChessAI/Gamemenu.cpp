//
// Created by rasyt on 2/7/2022.
//

#include "Gamemenu.h"


void Chess::Gamemenu::addfonts(sf::RenderWindow *window) {
    sf::Text Play;
    sf::Text Options;
    sf::Text Quit;
    sf::Font font;

    Play.setString("Play");
    Options.setString("Options");
    Quit.setString("Quit");


    Play.setFont(font);
    Options.setFont(font);
    Quit.setFont(font);


    Play.setCharacterSize(24);
    Options.setCharacterSize(24);
    Quit.setCharacterSize(24);

    Play.setFillColor(sf::Color(0, 0, 0));
    Options.setFillColor(sf::Color(0, 0, 0));
    Quit.setFillColor(sf::Color(0, 0, 0));


    Play.setStyle(sf::Text::Bold);
    Options.setStyle(sf::Text::Bold);
    Quit.setStyle(sf::Text::Bold);

    Play.setPosition();
    Options.setPosition();
    Quit.setPosition();


    window->draw(Play);
    window->draw(Options);
    window->draw(Quit);

}

bool Chess::Gamemenu::playbuttonpressed(float posx, float posy) {


}


bool Chess::Gamemenu::optionsbuttonpressed(float posx, float posy) {




}

bool Chess::Gamemenu::quitbuttonpressed(float posx, float posy) {




}


bool Chess::Gamemenu::loadgamemenu(sf::RenderWindow *window)
{
    sf::Texture background;
    sf::Sprite backsprite;
    background.loadFromFile("C:\\Users\\rasyt\\Pictures\\Saved Pictures\\chessui.jpg");
    backsprite.setTexture(background);
    //backsprite.setScale(960/1200, 960/800);
    backsprite.setPosition(0, 0);

    window->draw(backsprite);
    sf::RectangleShape PlayButton(sf::Vector2f(420.0f, 150.0f));
    PlayButton.setFillColor(sf::Color(255, 255, 255));

    sf::RectangleShape OptionsButton(sf::Vector2f(420.0f, 150.0f));
    OptionsButton.setFillColor(sf::Color(255, 255, 255));

    sf::RectangleShape Quitbutton(sf::Vector2f(420.0f, 150.0f));
    Quitbutton.setFillColor(sf::Color(255, 255, 255));

    PlayButton.setPosition(250, 150);
    OptionsButton.setPosition(250, 400);
    Quitbutton.setPosition(250, 650);

    window->draw(PlayButton);
    window->draw(OptionsButton);
    window->draw(Quitbutton);
    return false;
}

