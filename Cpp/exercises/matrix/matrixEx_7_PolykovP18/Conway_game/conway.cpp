#include <iostream>
#include <cstdlib>
#include "conway.h"

int getNumUser (std::string descriptor) {
    while (true) {
        std::cout << descriptor << std::endl;
        std::cout << "Enter a int value:  " ;
        int a {0} ;
        std::cin >> a;
        // check for previous retrieval varible value
        if (std::cin.fail()) {
            std::cin.clear(); // reloading cin
            std::cin.ignore(32767,'\n'); // clear buffer
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        } else {
            std::cin.ignore(32767,'\n'); // clear excess
            return a;
        }
    }
}

char ** constructorArr (int width, int height) {
    char ** ptrArr = new char * [width] ;
    for (int i = 0; i < width ; ++i) {
        ptrArr [i] = new char [height];
    }
    return ptrArr;
}

void destructorArr (char **arr, int width) {
    for (int i = 0; i < width; ++i) {
        delete [] arr [i];
    }
    delete []arr;
}

void filling (char **arr, int width , int height) {
    for (int i = 0 ; i < width ; ++i ) {
        for (int j = 0 ; j < height ; ++j ) {
            if ((i+j) % 2 == 0) {
                arr[i][j] = ' ' ;
            } else {
                arr[i][j] = '+';
            }
        }
    }
}

void revertfiling (char **arr, int width , int height) {
    for (int i = 0 ; i < width ; ++i ) {
        for (int j = 0 ; j < height ; ++j ) {
            if (arr[i][j] == ' ') {
                arr[i][j] = static_cast<char> ( getRandomNumber ( 46,126) );
            } else {
                arr[i][j] = ' ';
            }
        }
    }
}

void printArr (char **arr, int width, int height) {
    for (int i = 0; i < width ; ++i ) {
        for (int j = 0 ; j < height ; ++ j ) {
            std::cout << arr[i][j]<< " " ;
        }
    std::cout<<std::endl;
    }
}

int getRandomNumber(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // Evenly distribute a random number in our range
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

