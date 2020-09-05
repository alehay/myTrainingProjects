#ifndef ENEMY_H
#define ENEMY_H

#include "iostream"
#include "SFML/Graphics.hpp"
#include "gamecharacter.h"

class Enemy : public GameCharacter
{

public:
    Enemy (int x, int y);
   ~Enemy ();


};



#endif // ENEMY_H