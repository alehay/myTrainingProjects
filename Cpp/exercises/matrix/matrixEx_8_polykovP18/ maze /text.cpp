#include <iostream>
#include <cstdlib>

#include <SFML/Graphics.hpp>
#include <cmath>

#include "text.h"

void laibleSettings (int fieldWidth , sf::Text *heading1 , sf::Font *font , sf::RenderWindow * app,
     std::string StringCouterCellGen,  std::string StringCouterCellPass , std::string StringCouterCellFalse  ) {   

    int gap = 150;
    heading1->setFont( *font);
    heading1->setString ("locations in maze ");
    heading1->setCharacterSize(40);
    heading1->setFillColor(sf::Color::White);
    heading1->setPosition(sf::Vector2f(fieldWidth + 5, gap ));
    app->draw (*heading1);

    heading1->setString (StringCouterCellGen);
    heading1->setCharacterSize(50);
    heading1->setFillColor(sf::Color::Green);
    heading1->setPosition(sf::Vector2f(fieldWidth + 72, gap+50 ));
    app->draw (*heading1);

    heading1->setString (" long way now ");
    heading1->setCharacterSize(40);
    heading1->setFillColor(sf::Color::White);
    heading1->setPosition(sf::Vector2f(fieldWidth + 5, gap*2 ));
    app->draw (*heading1);

    heading1->setString (StringCouterCellPass);
    heading1->setCharacterSize(50);
    heading1->setFillColor(sf::Color(0,191,250,255));
    heading1->setPosition(sf::Vector2f(fieldWidth + 72, gap*2+50 ));
    app->draw (*heading1);

    heading1->setString (" thrown way ");
    heading1->setCharacterSize(40);
    heading1->setFillColor(sf::Color::White);
    heading1->setPosition(sf::Vector2f(fieldWidth + 5, gap*3 ));
    app->draw (*heading1);

    heading1->setString (StringCouterCellFalse);
    heading1->setCharacterSize(50);
    heading1->setFillColor(sf::Color::Red);
    heading1->setPosition(sf::Vector2f(fieldWidth + 72, gap*3+50 ));
    app->draw (*heading1);
    
}