
#include <iostream>
#include <cstdlib>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "maze.h"


// declare a dynamic two-dimensional array
//allocate memory
//
char ** constructorArr (int width, int height) {
    //array of pointers
    char ** ptrArr = new char * [width] ;
    for (int i = 0; i < width ; ++i) {
        ptrArr [i] = new char [height];
    }
    return ptrArr;
}
//freeing memory
void destructorArr (char **arr, int width) {
    //first we clear the internal
    for (int i = 0; i < width; ++i) {
        delete [] arr [i];
    }
    //delete the external pointer to an array of pointers
    delete []arr;
}
int getRandomNumber(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // Evenly distribute a random number in our range
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
// field generation
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
// rendering field 
void drowGrid (int cellSize, char **arr, int cellNumWidth, int cellNumHeight,
                sf::RenderWindow *app, sf::RectangleShape  *rect , int * couterCellGen , int * couterCellPass , int * couterCellFalse  ) {
    *couterCellFalse = 0;
    *couterCellGen = 0;
    *couterCellPass = 0;
    
    for ( int i = 0 ; i < cellNumWidth ; i++) {
        for ( int j = 0; j < cellNumHeight ; j++) {
            //setting colors

            // uncomment for coloring
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
                *couterCellGen +=1 ;
            }
            if (arr[i][j]== g_currentCell) {
                rect->setPosition (cellSize * i , cellSize * j);
                rect->setFillColor(sf::Color::Red);
            }
            if (arr [i][j]== g_visitedSulution) {
                rect->setPosition (cellSize * i , cellSize * j);
                rect->setFillColor(sf::Color(0,191,250,255));
                *couterCellPass +=1; 
            }
            if (arr [i][j]== g_out) {
                rect->setPosition (cellSize * i , cellSize * j);
                rect->setFillColor(sf::Color::Yellow);
            }
            if (arr [i][j] == g_wrong) {
                rect->setPosition (cellSize * i , cellSize * j);
                rect->setFillColor(sf::Color::Red);                
                *couterCellFalse +=1;
            }
            // drawing command
            app->draw(*rect);
        }
    }
}

// returns a structure with an array of neighibor unoccupied cells,
// and their number
cellStack getNeighbor (char **arr, cell * curentCell , int width, int height, int distance , char sign ) {

     // differential due to cell pitch
     // for generation - 2
     // for passing - 1
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
            char mazeCellCurrent {0};
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
    //the midpoint is calculated using the standard mean algorithm
    arr [addX][addY] = g_visitedCell;
}

// maze generation
void mazeGenStep (char **arr, std::vector <cell> * cellStackWay , cell *  curentCell ,
                                                    int widthField ,int heightField , bool * genEnded) {
    bool NotMoveMade {true}; // switch
    while (NotMoveMade) {
        //the cell in which we are is marked as visited.
        arr[curentCell->x][curentCell->y] = g_visitedCell;  
        // initialize the future move
        cell cellNegibordTarget ;
        // get neighboring cells and their number
        cellStack cellStacNeighibord =  getNeighbor ( arr, curentCell ,
        widthField , heightField , 2 , g_visitedCell ) ;
            // if neighbors exist
        if (cellStacNeighibord.size != 0 ) {
            //choose a random neighbor
            int randNum = getRandomNumber (0, cellStacNeighibord.size - 1 );
            cellNegibordTarget = cellStacNeighibord.cells[randNum]; 
            removeWall (*curentCell, cellNegibordTarget, arr );
            //mark the point on the field as "current" for rendering
            arr[cellNegibordTarget.x][cellNegibordTarget.y] = g_currentCell;
            // we save the current cell on the stack 
            cellStackWay->push_back (*curentCell);
            //and the chosen neighbor
            // becomes current 
            *curentCell = cellNegibordTarget;
            NotMoveMade = false;                       
        } else { 
            //  if there are no more neighbors 
            // and the stack is not empty
           if (cellStackWay->size() > 0) {
               //forget the current element,
               //and take the top one from the stack
                *curentCell = cellStackWay->at(cellStackWay->size()-1);
                cellStackWay->pop_back();
           } else {
               //if the stack is empty it's over
               *genEnded = true;
               NotMoveMade = false;
           }
        }
    }
}

//  solution 
void mazeSolution (char **arr, std::vector <cell> * cellStackSolution , cell *  curentCell ,
                                                    int widthField , int heightField , cell * finishCell,  bool * sulutionEnded ) {

    bool NotMoveMade {true}; //switch
    while (NotMoveMade) {
        //  maybe we have already arrived?
        if ( (curentCell->x == finishCell->x) && (curentCell->y == finishCell->y)  ) {
            //Hooray !
            *sulutionEnded = true;
            return;
        }
        //the cell in which we are is marked as visited.
        arr[curentCell->x][curentCell->y] = g_visitedSulution;
        // initialize the future move
        cell cellNegibordTarget ;
        cellStack cellStacNeighibord =  getNeighbor ( arr, curentCell ,
        widthField , heightField , 1 , g_visitedSulution ) ;
        // get possible neighbors, where can we go
        if (cellStacNeighibord.size != 0 ) {
            //choose a random neighbor
            int randNum = getRandomNumber (0, cellStacNeighibord.size - 1 );
            cellNegibordTarget = cellStacNeighibord.cells[randNum];
            //mark the point on the field as "current" for rendering
            arr[cellNegibordTarget.x][cellNegibordTarget.y] = g_currentCell;
            // we save the current cell on the stack 
            cellStackSolution->push_back (*curentCell);
            //and the chosen neighbor
            // becomes current 
            *curentCell = cellNegibordTarget;
            NotMoveMade = false;

        } else {
            //  if there are no more neighbors 
            // and the stack is not empty
           if (cellStackSolution->size() != 0) {
                arr[curentCell->x][curentCell->y] = g_wrong;
                *curentCell = cellStackSolution->at(cellStackSolution->size()-1);
                
                cellStackSolution->pop_back();
                
           } else {
               //if the stack is empty it's over 
               // we got lost and starved to death
               *sulutionEnded = true;
           }
        }
    }
}


