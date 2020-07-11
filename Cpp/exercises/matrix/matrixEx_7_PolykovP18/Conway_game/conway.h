#ifndef CONWAY_H
#define CONWAY_H

int getNumUser (std::string descriptor);
char ** constructorArr (int width, int height) ;
void destructorArr (char **arr, int width);
void filling (char **arr, int width , int height);
void printArr (char **arr, int width, int height) ;
void revertfiling (char **arr, int width , int height);
int getRandomNumber(int min, int max) ;
int getNeighborNum (char **arr, int a , int width, int b ,int height) ;
void fillingFirstGeneration (char ** arr , int width , int height ,
                             int detensity);
void flip (char **A , char **B ) ;
char ** stepConwayLive (char **arr, char **buffer, int width, int height, int * population) ;
const char  g_emptyCell = ' ';
const char  g_liveCell = '*';

#endif // CONWAY_H
