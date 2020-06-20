/* task:
 *Write a logical function "isAutomurph" which returns the true value
 *if the number passed to it is automorphic (the last digits of its
 *square coincide with the number itself  e.g. 25^2 = 625
 *(by the assumption of the problem, an automorph is square)
 *
 * solution: (I will decide on my own)
 * ++++ 1) ask number user ( in 6ex ) (
 * 2)   atomorph test: (how?)
 *
 * +++      2.1) my idea :  calculate square root (only int , not int can't be an automorph)
 *          2.2)         number extraction
 *          2.3)         comparison and answer
 *
 */



#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for function time()

#include "auto_morph.h" // my heder file


int main()
{
    unsigned long  max = (getNumUser());
    for (unsigned long i = 1; i < max ; ++i) {

        if (isAutomorph(i)) {
            std::cout << "Обнаружен АВТОМОРФ :" << i << "/t" << "корень это " << getSqrt(i) << std::endl;
            for (int j = 0 ; j < 5 ; ++j){
            std::cout <<"____"<< std::endl;
            }
        }
    }
return 0;
}

//complet ( the decision is of course not very good )



