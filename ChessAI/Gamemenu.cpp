//
// Created by rasyt on 2/7/2022.
//

#include "Gamemenu.h"



void Chess::Gamemenu::addmenu2fonts(sf::RenderWindow *window, std::string topbuttonstr, std::string midbuttonstr, std::string bottomstr) {
    sf::Font font;
    if (!font.loadFromFile("C:\\Users\\rasyt\\Downloads\\montserrat\\Montserrat-Medium.otf"))
    {
        std::cout << "Error loading file";
    }


    sf::Text EasyAI;
    sf::Text MediumAI;
    sf::Text HumanOpponent;

    EasyAI.setFont(font);
    MediumAI.setFont(font);
    HumanOpponent.setFont(font);

    EasyAI.setString(topbuttonstr);
    MediumAI.setString(midbuttonstr);
    HumanOpponent.setString(bottomstr);


    EasyAI.setCharacterSize(50);
    MediumAI.setCharacterSize(50);
    HumanOpponent.setCharacterSize(50);

    EasyAI.setFillColor(sf::Color(0, 0, 0));
    MediumAI.setFillColor(sf::Color(0, 0, 0));
    HumanOpponent.setFillColor(sf::Color(0, 0, 0));


    EasyAI.setStyle(sf::Text::Bold);
    MediumAI.setStyle(sf::Text::Bold);
    HumanOpponent.setStyle(sf::Text::Bold);

    EasyAI.setPosition(400, 180);
    MediumAI.setPosition(350, 430);
    HumanOpponent.setPosition(400, 680);


    window->draw(EasyAI);
    window->draw(MediumAI);
    window->draw(HumanOpponent);


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


void Chess::Gamemenu::parseclicks(sf::RenderWindow *window) {
    sf::Event event;
    sf::Vector2i mousePos1 = sf::Mouse::getPosition(*window);
    int getposy = mousePos1.y;
    int getposx = mousePos1.x;

    while (window->pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::MouseButtonPressed:
                if (highlightplay(getposx, getposy))
                {
                    playbutton = true;
                    //load the second game menu here
                    //Easy AI, Medium AI, Human
                } else if (highlightoptions(getposx, getposy))
                {


                } else if (highlightquit(getposx, getposy))
                {
                    window->close();
                    break;
                }

        }
    }
}


void Chess::Gamemenu::createbuttons(sf::RenderWindow *window, float highlightx, float highlighty) {
    sf::Color green(118, 150, 86);
    sf::Texture background;
    sf::Sprite backsprite;
    background.loadFromFile("C:\\Users\\rasyt\\Pictures\\Saved Pictures\\chessui.jpg");
    backsprite.setTexture(background);
    backsprite.setPosition(0, 0);

    window->draw(backsprite);

    sf::RectangleShape PlayButton(sf::Vector2f(420.0f, 150.0f));
    if (highlightplay(highlightx, highlighty))
    {
        PlayButton.setFillColor(green);
    } else
    {
        PlayButton.setFillColor(sf::Color(255, 255, 255));
    }

    sf::RectangleShape OptionsButton(sf::Vector2f(420.0f, 150.0f));
    if (highlightoptions(highlightx, highlighty))
    {
        OptionsButton.setFillColor(green);
    } else
    {
        OptionsButton.setFillColor(sf::Color(255, 255, 255));
    }


    sf::RectangleShape Quitbutton(sf::Vector2f(420.0f, 150.0f));
    if (highlightquit(highlightx, highlighty))
    {
        Quitbutton.setFillColor(green);
    } else
    {
        Quitbutton.setFillColor(sf::Color(255, 255, 255));
    }

    PlayButton.setPosition(250, 150);
    OptionsButton.setPosition(250, 400);
    Quitbutton.setPosition(250, 650);

    window->draw(PlayButton);
    window->draw(OptionsButton);
    window->draw(Quitbutton);
}


void Chess::Gamemenu::loadplaymenu(sf::RenderWindow *window, float highlightx, float highlighty) {
    createbuttons(window, highlightx, highlighty);
    addmenu2fonts(window, "Easy AI", "Medium AI", "Human");
}


bool Chess::Gamemenu::loadgamemenu(sf::RenderWindow *window, float highlightx, float highlighty)
{
    createbuttons(window, highlightx, highlighty);
    addmenu2fonts(window, "Play", "Options", "Quit");
    return false;
}


bool Chess::Gamemenu::geteasyai() {
    return easyai;
}

bool Chess::Gamemenu::getmediumai() {
    return mediumai;
}

bool Chess::Gamemenu::gethumanopponent() {
    return humanopponent;
}
bool Chess::Gamemenu::getplaybutton() {
    return playbutton;
}






