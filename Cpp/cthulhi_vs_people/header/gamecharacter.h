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
    struct coordinates {
        short leng_x {1};
        short wid_y {1};
        short dep_z {0};
    };
    sf::Texture charTexture ;
    sf::Sprite sprite;
    float currentFrame {0};


    ///////////  ATTRIBUTES ///////////////
    coordinates position;
    

public:
    GameCharacter (short int pos_x, short int pos_y, short int pos_z = 0);
    ~GameCharacter ();
    void show(sf::RenderWindow * app, float time); 

private: 
    void loadTexture ();
    void loadSprite();




};



#endif // CHARACTER_H