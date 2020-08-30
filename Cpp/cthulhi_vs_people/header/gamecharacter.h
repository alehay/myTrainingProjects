#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

#include "iostream"
#include "SFML/Graphics.hpp"
#include "../header/resources.h"

class GameCharacter
{
private:
  
    const std::string PATH_TEXTURE_FILE {"texture/Demon.png"} ;
    //  one size tile 
    short int texTile{48};  

    sf::Texture charTexture ;
    sf::Sprite sprite;
    float currentFrame {0}; // 
    

    ///////////  ATTRIBUTES //////////
    sf::Vector2f position;
    float speedMove {0.5};     

    /////////// Charackter state ////////
    enum class State {
        STANDS, //default state
        MOVES,
        ATTACK
     };

    State currentState;

public:
    GameCharacter (short int pos_x, short int pos_y);
    ~GameCharacter ();
    void show(sf::RenderWindow * app, float time); 

    void movNorth (float time);
    void movSouth (float time);
    void movWest (float time);
    void movEast (float time);
    void attack (float time);
    

private: 
    void loadTexture ();
    void loadSprite();
    



};



#endif // CHARACTER_H