//
// Created by rasyt on 2/7/2022.
//

#include "Gamemenu.h"


void Chess::Gamemenu::addfonts(sf::RenderWindow *window) {
    sf::Font font;
    if (!font.loadFromFile("C:\\Users\\rasyt\\Downloads\\montserrat\\Montserrat-Medium.otf"))
    {
        std::cout << "Error loading file";
    }
    sf::Text Play;
    sf::Text Options;
    sf::Text Quit;

    Play.setFont(font);
    Options.setFont(font);
    Quit.setFont(font);

    Play.setString("Play");
    Options.setString("Options");
    Quit.setString("Quit");


    Play.setCharacterSize(50);
    Options.setCharacterSize(50);
    Quit.setCharacterSize(50);

    Play.setFillColor(sf::Color(0, 0, 0));
    Options.setFillColor(sf::Color(0, 0, 0));
    Quit.setFillColor(sf::Color(0, 0, 0));


    Play.setStyle(sf::Text::Bold);
    Options.setStyle(sf::Text::Bold);
    Quit.setStyle(sf::Text::Bold);

    Play.setPosition(400, 180);
    Options.setPosition(350, 430);
    Quit.setPosition(400, 680);


    window->draw(Play);
    window->draw(Options);
    window->draw(Quit);

}

bool Chess::Gamemenu::highlightplay(float clickposx, float clickposy) {
    float playbuttonx = 250;
    float playbuttony = 150;
    if (clickposx >= 250 and clickposx <= playbuttonx + 420 and clickposy >= 150 and clickposy <= playbuttony + 150)
    {
        return true;
    }
    return false;
}


bool Chess::Gamemenu::highlightoptions(float clickposx, float clickposy) {
    float optionbuttonx = 250;
    float optionbuttony = 400;
    if (clickposx >= 250 and clickposx <= optionbuttonx + 420 and clickposy >= 400 and clickposy <= optionbuttony + 150)
    {
        return true;
    }
    return false;
}

bool Chess::Gamemenu::highlightquit(float clickposx, float clickposy) {
    float quitbuttonx = 250;
    float quitbuttony = 650;
    if (clickposx >= 250 and clickposx <= quitbuttonx + 420 and clickposy >= 650 and clickposy <= quitbuttony + 150)
    {


        return true;
    }
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

    addfonts(window);
    return false;
}


