#include <iostream>
#include "partybit.h"
#include <cmath>

// binary conversion decimal number
void binaryConversion ( int *binNumnArr, int decNum ){
    if (!binNumnArr)
    return;

// const - for protect adress for chenged
// protect If user passed null pointer as array
    for(int i=0; decNum>0; i++){
    binNumnArr[i]=decNum%2;
    decNum= decNum/2;
    }
}

int getNumUser (){
    while (true){ // endless cycle
        std::cout << "Enter a int value: ";
        int a;
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

void addParityBit (int *binNumnArr, int sizeArr ) {
    if (parityChek(binNumnArr, sizeArr )) {
        return;
    }

    for (int i = sizeArr; i > 0 ; i-- ){
        binNumnArr[i] = binNumnArr [i-1];
    }
    binNumnArr[0]=1;
}

bool parityChek ( int *binNumnArr,  int sizeArr ){
    int numOneBit {0};//number of bits equal to one
    for (int i = 0; i < sizeArr ; i++){
        if (binNumnArr[i] == 1) {
        numOneBit++;
        }
    }

    if ((numOneBit & 1) != 0) {
        return false;
    } else {
        return true;
    }
}

int decConversion(int *binNumnArr,  int sizeArr) {
    int binaryDigit = 1 << sizeArr; // determine the maximum binary bit
    int number = {0};

    //conversion
    for (int i = sizeArr; i >= 0 ; i-- ){
       number = number + binNumnArr[i]*binaryDigit ;
       binaryDigit = binaryDigit >> 1;
    }
    return number;
}
