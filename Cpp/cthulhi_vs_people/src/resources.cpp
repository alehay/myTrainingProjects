
#include "random"
#include "../header/resources.h"

//returns a rand value between "min" and "max" inclusive
int getRandomNumber(int min, int max) {

    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // Evenly distribute a random number in our range
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void keyboardHandling (GameCharacter & Character, float time){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                Character.movWest(time);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                Character.movEast(time);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                Character.movNorth(time);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                Character.movSouth(time);
            }
            
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                Character.attack(time);
            }
}
