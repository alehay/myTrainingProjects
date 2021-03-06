#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

#include "iostream"
#include "SFML/Graphics.hpp"
#include "../header/resources.h"

class GameCharacter
{
private:
    const std::string PATH_TEXTURE_FILE {"texture/demon-idle.png"} ;
    short int textureTileSize{48}; 
    struct coordinates {
        short leng_x {1};
        short wid_y {1};
        short dep_z {0};
    };
    sf::Texture charTexture ;
    sf::Sprite sprite;



    ///////////  ATTRIBUTES ///////////////
    coordinates position;
    

public:
    Character (/* args */);
    ~Character ();
    void show(sf::RenderWindow * app); 

private: 
    void loadTexture ();




};



#endif // CHARACTER_H