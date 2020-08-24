#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

#include "iostream"
#include "SFML/Graphics.hpp"
#include "../header/resources.h"

class GameCharacter
{
private:
    const std::string PATH_TEXTURE_FILE {"texture/demon-idle.png"} ;
    short int textureTileSize{48*2};  

    sf::Texture charTexture ;
    sf::Sprite sprite;
    float currentFrame {0};


    ///////////  ATTRIBUTES ///////////////
    sf::Vector2f position;
    float speedMove ;     

public:
    GameCharacter (short int pos_x, short int pos_y);
    ~GameCharacter ();
    void show(sf::RenderWindow * app, float time); 

    void movNorth (float time);
    void movSouth (float time);
    void movWest (float time);
    void movEast (float time);


private: 
    void loadTexture ();
    void loadSprite();




};



#endif // CHARACTER_H