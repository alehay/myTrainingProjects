#include "../header/gamecharacter.h"
#include "iostream"

GameCharacter::GameCharacter(short int pos_x, short int pos_y ) 
{
speedMove = 0.5;
position.x = { static_cast <float> (pos_x) };
position.y = { static_cast <float> (pos_y) };

loadTexture();
loadSprite();

}

GameCharacter::~GameCharacter()
{

}

void GameCharacter::show (sf::RenderWindow * app, float time) {
    // animation speed
    currentFrame += 0.008*time;
    if (currentFrame > 6) {
        currentFrame -=6;
    }
    sprite.setPosition(position);
    // texture size 160  - 1 frame
    // texture height - 144
    // demon
    sprite.setTextureRect(sf::IntRect(160 * static_cast<int> (currentFrame), 
    0 , 160, 144));
    sprite.setScale(1.5 , 1.5 );
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

void GameCharacter::movNorth (float time) {
    position.y = position.y - time * speedMove;
}

void GameCharacter::movSouth (float time){
    position.y = position.y + time * speedMove;
}

void GameCharacter::movWest(float time){ 
    position.x = position.x - time * speedMove ;

}

void GameCharacter::movEast (float time) {
    position.x = position.x +  time*speedMove;
}