#include <iostream>
#include <cstdlib>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "maze.h"

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

int getRandomNumber(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // Evenly distribute a random number in our range
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void startGridGen (char **arr, int width, int height) {
    for ( int i = 0 ; i < width; ++i) {
        for (int j = 0 ; j < height; ++j) {
            // if coordinates are even
            if (((i & 1) && (j & 1) ) && !((i == width - 1) || (j == height - 1)))      {
                arr [i][j] = g_emptyCell;
            } else {
                arr [i][j] = g_wallCell ;
            }
        }
    }
}

void drowGrid (int cellSize, char **arr, int cellNumWidth, int cellNumHeight,
                sf::RenderWindow *app, sf::RectangleShape  *rect  ) {
    for ( int i = 0 ; i < cellNumWidth ; i++) {
        for ( int j = 0; j < cellNumHeight ; j++) {
           /* if ( arr[i][j] == g_wallCell ) {
                rect->setPosition (cellSize * i , cellSize * j);
                rect->setFillColor(sf::Color::Black);
            }
            if (arr[i][j] == g_emptyCell) {
                rect->setPosition (cellSize * i , cellSize * j);
                rect->setFillColor(sf::Color::Black);
            } */
            if (arr[i][j] == g_visitedCell) {
                rect->setPosition (cellSize * i , cellSize * j);
                rect->setFillColor(sf::Color::Green);
            }
            if (arr[i][j]== g_currentCell) {
                rect->setPosition (cellSize * i , cellSize * j);
                rect->setFillColor(sf::Color::Red);
            }
            if (arr [i][j]== g_visitedSulution) {
                rect->setPosition (cellSize * i , cellSize * j);
                rect->setFillColor(sf::Color(0,191,250,255));
            }
            if (arr [i][j]== g_out) {
                rect->setPosition (cellSize * i , cellSize * j);
                rect->setFillColor(sf::Color::Yellow);
            }
            if (arr [i][j] == g_wrong) {
                rect->setPosition (cellSize * i , cellSize * j);
                rect->setFillColor(sf::Color::Red);                
            }

            app->draw(*rect);
        }
    }
}

// returns a structure with an array of neighibor unoccupied cells,
// and their number
cellStack getNeighbor (char **arr, cell * curentCell , int width, int height, int distance , char sign ) {

     // differential due to cell pitch
    int x = curentCell->x; // take the coordinates of the target object
    int y = curentCell->y;

    //sorting out neighbors
    cell north =  { x, y - distance };
    cell east =  { x + distance, y };
    cell south =  { x , y + distance };
    cell west =  { x - distance, y };

    // keep potential neighbors
    cell neighboringCell[4] = { north, east, south, west } ;

    // initializean empty  the structure to return
    cellStack neighiborResult;
    neighiborResult.size  = 0;
    neighiborResult.cells  =  new cell [4];
    int size {0}; //  temporary length
    // checking neighbors
    for (int i = 0; i < 4 ; i++) {
        //do not go outside the field
        if (neighboringCell[i].x > 0 && neighboringCell[i].x < width - 1
                && neighboringCell[i].y > 0 && neighboringCell[i].y < height - 1){
            // do not go outside the field
            char mazeCellCurrent = {0};
            // see the value of the neighbor
            mazeCellCurrent = arr [neighboringCell[i].x ] [neighboringCell[i].y];
            //cell TempCellCurrent = neighboringCell[i] ;
            // if not a wall and not visited
            if   ( mazeCellCurrent != g_wallCell && mazeCellCurrent != g_wrong && mazeCellCurrent != sign ) {
                neighiborResult.cells[size] = neighboringCell[i];
                //neighiborResult.cells[size] = TempCellCurrent;
                size++;
            }
        }
    }
    neighiborResult.size = size;
    return neighiborResult ;
}


void removeWall (cell first , cell last, char ** arr) {
    int xDiff = (first.x + last.x) ;
    int yDiff = (first.y + last.y) ;
    int addX =  xDiff / 2;
    int addY = yDiff / 2;
    arr [addX][addY] = g_visitedCell;
}

void mazeGenStep (char **arr, std::vector <cell> * cellStackWay , cell *  curentCell ,
                                                    int widthField ,int heightField , bool * genEnded ) {


    bool NotMoveMade {true};
    while (NotMoveMade) {
        arr[curentCell->x][curentCell->y] = g_visitedCell;
        cell cellNegibordTarget ;
        cellStack cellStacNeighibord =  getNeighbor ( arr, curentCell ,
        widthField , heightField , 2 , g_visitedCell ) ;
        if (cellStacNeighibord.size != 0 ) {
            int randNum = getRandomNumber (0, cellStacNeighibord.size - 1 );
            cellNegibordTarget = cellStacNeighibord.cells[randNum];
            removeWall (*curentCell, cellNegibordTarget, arr );
            arr[cellNegibordTarget.x][cellNegibordTarget.y] = g_currentCell;
            cellStackWay->push_back (*curentCell);
            *curentCell = cellNegibordTarget;
            NotMoveMade = false;
        } else {
           if (cellStackWay->size() > 0) {
                *curentCell = cellStackWay->at(cellStackWay->size()-1);
                cellStackWay->pop_back();
           } else {
               *genEnded = true;
               NotMoveMade = false;
           }
        }
    }
}




void mazeSolution (char **arr, std::vector <cell> * cellStackSolution , cell *  curentCell ,
                                                    int widthField , int heightField , cell * finishCell,  bool * sulutionEnded ) {


    bool NotMoveMade {true};
    while (NotMoveMade) {
        if ( (curentCell->x == finishCell->x) && (curentCell->y == finishCell->y)  ) {
            *sulutionEnded = true;
            return;
        }

        arr[curentCell->x][curentCell->y] = g_visitedSulution;

        cell cellNegibordTarget ;
        cellStack cellStacNeighibord =  getNeighbor ( arr, curentCell ,
        widthField , heightField , 1 , g_visitedSulution ) ;
        if (cellStacNeighibord.size != 0 ) {
            int randNum = getRandomNumber (0, cellStacNeighibord.size - 1 );
            cellNegibordTarget = cellStacNeighibord.cells[randNum];

            arr[cellNegibordTarget.x][cellNegibordTarget.y] = g_currentCell;
            cellStackSolution->push_back (*curentCell);
            *curentCell = cellNegibordTarget;
            NotMoveMade = false;

        } else {
           if (cellStackSolution->size() >= 0) {
                arr[curentCell->x][curentCell->y] = g_wrong;
                *curentCell = cellStackSolution->at(cellStackSolution->size()-1);
                
                cellStackSolution->pop_back();
                
           } else {
               *sulutionEnded = true;
           }
        }
    }
}


