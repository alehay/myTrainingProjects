/* Game live conway live
 *  1) fill the matrix with random values but parameterized
 *  +   -get parameters
 *  +   -init filed
 *  +
 */

#include <iostream>
#include <unistd.h> // sleep
#include "conway.h"

//size filed

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));

    int width   = getNumUser ("width");
    int height  = getNumUser ("height");
    int density = getNumUser ( "density degree from 1 to 100 ");
    int group   = getNumUser ("grouping degree from 1 to 100 ");

    char **arr1 = constructorArr (width, height);
    char **arr2 = constructorArr (width, height);

    char **arr = arr1 ;

    filling (arr, width, height);

    for (int i = 0; i < 1000; ++i) {
        std::system("clear");
        printArr (arr, width, height);
        revertfiling (arr, width, height);
        usleep(300000);
        //sleep (1);
    }
    destructorArr ( arr, width);
    return 0;
}
