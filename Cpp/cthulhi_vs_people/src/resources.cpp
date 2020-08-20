
#include "random"
#include "../header/resources.h"

//returns a rand value between "min" and "max" inclusive
int getRandomNumber(int min, int max) {

    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // Evenly distribute a random number in our range
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
