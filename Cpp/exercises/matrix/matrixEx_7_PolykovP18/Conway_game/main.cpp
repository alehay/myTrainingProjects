/* Game live conway live*/

#include <iostream>
#include <unistd.h> // sleep
#include "conway.h"

int main()
{
    srand(static_cast<unsigned int>(time(NULL))); // init random  seed
    int width   = getNumUser ("width");
    int height  = getNumUser ("height");
    int density = getNumUser ( "density degree from 1 to 100 ");
    // main pointers 
    char **arr1 = constructorArr (width, height); 
    char **arr2 = constructorArr (width, height);
    int population {0} ;
    // pointer to control ;
    char **arr = arr1 ;
    char **arrBuf = arr2;
    filling (arr, width, height);
    fillingFirstGeneration (arr, width, height , density);
    //game cycle
    for (int i = 0; i < 4000; ++i) {
        std::system("clear");
        arr = stepConwayLive ( arr , arrBuf, width , height , &population) ;
        printArr ( arr, width, height);
        std::cout << "iter : " << i << "\t" << "population : " << population << std::endl ;
        // flip pointers 
        // for cleanliness of generation
        if (i % 2 == 0) {
            arr = arr1;
            arrBuf=arr2;
        } else {
            arr = arr2;
            arrBuf = arr1;
        }
        //we wait
        usleep(120000);   // microsec
        //sleep (1);      // sec
    }
    destructorArr ( arr1, width);
    destructorArr ( arr2, width);
    return 0;
}
