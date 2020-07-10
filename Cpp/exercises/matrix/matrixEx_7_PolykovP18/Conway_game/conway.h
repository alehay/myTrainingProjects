#ifndef CONWAY_H
#define CONWAY_H

int getNumUser (std::string descriptor);
char ** constructorArr (int width, int height) ;
void destructorArr (char **arr, int width);
void filling (char **arr, int width , int height);
void printArr (char **arr, int width, int height) ;
void revertfiling (char **arr, int width , int height);
int getRandomNumber(int min, int max) ;
int getRandomNumber(int min, int max) ;

#endif // CONWAY_H
