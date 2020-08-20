#include "../header/gamecharacter.h"
#include "iostream"
GameCharacter::GameCharacter(short int pos_x, short int pos_y, short int pos_z ){

position.leng_x = pos_x;
position.wid_y = pos_y;
position.dep_z = pos_z; 

loadTexture();
loadSprite();

}

GameCharacter::~GameCharacter()
{

}

void GameCharacter::show (sf::RenderWindow * app, float time) {
    currentFrame += 0.008*time;
    if (currentFrame > 6) {
        currentFrame -=6;
    }
    sprite.setPosition(position.leng_x , position.wid_y);

    sprite.setTextureRect(sf::IntRect(160 * static_cast<int> (currentFrame), 
    0 , 160, 144));
    
    app->draw(sprite);
}

void GameCharacter::loadTexture (){
    charTexture.loadFromFile (
        PATH_TEXTURE_FILE,sf::IntRect (
            0, 0,
            160*6, 144));
}


void GameCharacter::loadSprite () {
    sprite.setTexture(charTexture);
}