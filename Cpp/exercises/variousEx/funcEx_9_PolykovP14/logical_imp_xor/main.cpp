 /*
  *
  *
  */


#include <iostream>
#include "logical_imp_xor.h"

int main()
{
    for (int i = 0 ; i < 2; ++i ) {
        for (int j = 0 ; j < 2; ++j) {
            std::cout << i << " and " << j << " is " <<
                      imp(i,j) << std::endl;
        }
    }

    std::cout << std::endl;

    for (int i = 0 ; i < 2; ++i ) {
        for (int j = 0 ; j < 2; ++j) {
            std::cout << i << " and " << j << " is " <<
                      myXor(i,j) << std::endl;
        }
    }

    return 0;
}

//COMPLET
