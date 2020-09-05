#include "../header/gamecharacter.h"
#include "iostream"

GameCharacter::GameCharacter(short int pos_x , short int pos_y  ) {
    position.x  = pos_x;
    position.y  = pos_y;
    loadTexture();
    loadSprite();
    currentState = State::STANDS;
}

GameCharacter::~GameCharacter()
{

}

void GameCharacter::show (sf::RenderWindow * app, float time) {
    
    sprite.setPosition(position);

    //stand animation 
    if (currentState == State::STANDS) {
        // animation speed 
        currentFrame += 0.008*time;
        if (currentFrame > 6) {
            currentFrame -=6;
        }

        sprite.setTextureRect (
            sf::IntRect(texTile * int (currentFrame), texTile * 1,
            texTile, texTile ));
        sprite.setScale( 1, 1 * 1 );
    }

    if (currentState == State::ATTACK ) {
        currentFrame += 0.008*time;
        if (currentFrame > 10) {
            currentFrame -=10;
            // reset attack animation 
            // after 1 time
            currentState = State::STANDS;

        }
    

        sprite.setTextureRect (
            sf::IntRect(texTile * int (currentFrame), 
            texTile * 0 , texTile, texTile));
    } 


    app->draw(sprite);
}

/////// Load All image for all animation /// 
void GameCharacter::loadTexture (){
    charTexture.loadFromFile (PATH_TEXTURE_FILE,sf::IntRect (
        0, 0, 480, 194));
}


void GameCharacter::loadSprite () {
    sprite.setTexture(charTexture);
     currentState = State::ATTACK;
}

void GameCharacter::movNorth (float time) {
    position.y = position.y - time * speedMove;
     currentState = State::STANDS;
}

void GameCharacter::movSouth (float time){
    position.y = position.y + time * speedMove;
}

void GameCharacter::movWest(float time){ 

    
    position.x = position.x - time * speedMove ;

}

void GameCharacter::movEast (float time) {

    position.x = position.x + time*speedMove;

}

void GameCharacter::attack (float time) {
    currentState = State::ATTACK;

}