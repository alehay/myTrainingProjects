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
            arr[i][j] = g_emptyCell ;

        }
    }
}

void revertfiling (char **arr, int width , int height) {
    for (int i = 0 ; i < width ; ++i ) {
        for (int j = 0 ; j < height ; ++j ) {
            if (arr[i][j] == g_liveCell) {
                arr[i][j] = g_emptyCell;
            } else {
                arr[i][j] = g_liveCell;
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

void fillingFirstGeneration (char ** arr , int width , int height ,
                             int density ) {
    density = 100 - density ;
    for (int i = 0 ; i < width ; ++i ) {
        for (int j = 0 ; j < height ; ++j ) {
            if ( (getRandomNumber (0,90) - density/3 > getRandomNumber (0, density + 30)) ) {
                arr[i][j] = g_liveCell ;
            } else {
                arr[i][j] = g_emptyCell;
            }
        }
    }
}

int getNeighborNum (char **arr, int a , int width, int b ,int height) {
    short int neighibor {0};
    for ( int i = -1 ; i < 2 ; ++i ) {
        for ( int j = - 1 ; j < 2 ; ++j  ) {
            // exclude from check:
            // parent cell
            if ( i == 0 && j == 0 ) {
                continue;
            }
            //exclude from check
            // going abroad
            if ( (a + i < 0) || (b + j < 0) ||
               (a + i >= width) || (b + j >= height ) ) {
                continue;
            }

            if (arr[a+i][b+j] == g_liveCell) {
                ++neighibor;
            }
        }
    }
    return neighibor;
}

char ** stepConwayLive (char **arr, char **buffer, int width, int height) {
    for (int i = 0 ; i < width ; ++i) {
        for (int j = 0; j < height ; ++j) {
            int neighibor {0};
            neighibor = getNeighborNum (arr, i , width , j , height);
            buffer [i][j] = arr [i][j];
            if (arr [i][j] == g_emptyCell) {
                if (neighibor == 3) {
                    buffer [i][j] = g_liveCell;
                }
            }
            if (arr[i][j] == g_liveCell) {
                if ( (neighibor < 2) || (neighibor > 3) ) {
                    buffer [i][j] = g_emptyCell;
                }
            }
        }
    }
    return  buffer;
}

void flip (char **A , char **B ) {
    char **temp = A;
    A = B;
    B = temp;
}
