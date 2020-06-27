#include <iostream>
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for function time()
#include "auto_morph.h" // my heder file

//user enters a number into the console
unsigned long int getNumUser (){
    while (true){ // endless cycle
        std::cout << "Enter a int value: ";
        unsigned long a {0};
        std::cin >> a;
        // check for previous retrieval varible value
        if (std::cin.fail()) // if previous knowledge extraction fails
            {
                std::cin.clear(); // reloading cin
                std::cin.ignore(32767,'\n'); // clear buffer
                std::cout << "Oops, that input is invalid.  Please try again.\n";
            }
            else
            {
                std::cin.ignore(32767,'\n'); // clear excess

                return a;
            }
        }
    }

unsigned getSqrt(unsigned long l){
      unsigned long temp, div = l;
      unsigned rslt = (unsigned)l;
      if (l <= 0)
            return 0;
      while (1)
      {
            temp = l  / div + div;
            div =  temp >>  1;
            div += temp  & 1;
            if  (rslt > div)
                   rslt = (unsigned)div;
            else
            {

                  return rslt;
            }
      }
}

void getExtractedDigits (long numberFromExtract , int *arrayToExtract , int arrayLeght ){
    for (int i = 0; i <= arrayLeght; ++i){
        arrayToExtract[i] = numberFromExtract % 10;
        numberFromExtract /= 10;
    }

}

bool  isAutomorph (long testingNum) {
    int sqrtNum {getSqrt(testingNum)} ;
    int digit {10};
    // only integer root values without rounding
    if ( !(testingNum-sqrtNum*sqrtNum) ) {
        while (true) {
            if (sqrtNum == 0){
                return true;
            } else {
                if (testingNum % digit == sqrtNum % digit){
                    testingNum /= 10;
                    sqrtNum /= 10;
                }else{
                    return false;
                }

            }

        }

    }
    return false;
}


