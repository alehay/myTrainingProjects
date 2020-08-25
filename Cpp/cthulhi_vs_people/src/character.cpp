#include "../header/gamecharacter.h"
#include "iostream"

GameCharacter::GameCharacter(short int pos_x, short int pos_y ) 
{
speedMove = 0.5;
position.x = { static_cast <float> (pos_x) };
position.y = { static_cast <float> (pos_y) };

loadTexture(currentState);
loadSprite();
currentState = State::STANDS;
}

GameCharacter::~GameCharacter()
{

}

void GameCharacter::show (sf::RenderWindow * app, float time) {
    // animation speed
   /*
   
    currentFrame += 0.008*time;
    if (currentFrame > 6) {
        currentFrame -=6;
    }
    */ 
    sprite.setPosition(position);
    // texture size 160  - 1 frame
    // texture height - 144
    // demon
    
    loadTexture(currentState);

    if (currentState == State::STANDS) {
        currentFrame += 0.008*time;
        if (currentFrame > 6) {
            currentFrame -=6;
        }

        sprite.setTextureRect (
            sf::IntRect(160 * static_cast<int> (currentFrame), 
            0 , 160, 144));
        sprite.setScale(direction * 2, 1 * 2 );
    }

    if (currentState == State::ATTACK ) {
        currentFrame += 0.008*time;
        if (currentFrame > 11) {
            currentFrame -=11;
        }

        sprite.setTextureRect (
            sf::IntRect(240 * static_cast<int> (currentFrame), 
            0 , 240, 192));
        sprite.setScale(direction * 2, 2  );
    } 


    app->draw(sprite);
}

void GameCharacter::loadTexture (State){
    if (currentState == State::STANDS) {    
        charTexture.loadFromFile (
            PATH_TEXTURE_FILE,sf::IntRect (
                0, 0,
                160*6, 144));
    }
    if (currentState == State::ATTACK) {
        charTexture.loadFromFile (
            PATH_TEXTURE_ATTACK,sf::IntRect (
                0, 0,
                240*11, 192));
    }


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
    if (direction < 0 ) {
        direction *= -1;  
    }
    position.x = position.x - time * speedMove ;

}

void GameCharacter::movEast (float time) {
    if (direction > 0 ) {
        direction *= -1;  
    }
    position.x = position.x + time*speedMove;

}

void GameCharacter::attack (float time) {
    currentState = State::ATTACK;

}