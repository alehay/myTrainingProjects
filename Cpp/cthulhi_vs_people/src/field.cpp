
#include "iostream"
#include <vector>
#include <SFML/Graphics.hpp>
#include "../header/resources.h"
#include "../header/field.h"

// constructor with parametr
field::field(short int length, short int width,short int depth) {
    // save parametrs for generation
    lengthField = length;
    widthField = width;
    depthField = depth;

    // load texture packe
    loadTexturePack0();
    loadSprite();

    //allocate memory for a 3-dimensional array
    fieldArrayCell = new char **  [lengthField];
    for (int i = 0; i < lengthField ; i++) {
        fieldArrayCell [i] = new char * [widthField];
        for (int j = 0; j < widthField; ++j){
            fieldArrayCell [i][j] = new char [depthField];
        }
    }
    // initial generation as a grid
    startGridMazeGenerationField();
    // generation of maze moves by back-tracking method
    mazeGenerationField();

    randomizationCellType(); 

}

field::~field() {
    for (int i = 0; i <  lengthField; i++) {
        for (int j = 0; j < widthField; j++ ) {
            delete [] fieldArrayCell [i][j];
        }
        delete []fieldArrayCell [i];
    }
    delete []  fieldArrayCell;
}


//RENDER field
void field::show (sf::RenderWindow * app) {
    for ( int i = 0 ; i < lengthField ; i++) {
        for ( int j = 0; j < widthField ; j++) {
            sprite.setPosition(textureTileSize * i , textureTileSize * j);
            sprite.setTexture(getTextureChoice (i, j));
            app->draw(sprite);
        }
    }
}

// texture pack load
void field::loadTexturePack0() {
    stoneFloorType0.loadFromFile (
        PATH_TEXTURE_FILE,sf::IntRect(
        textureTileSize * 0, textureTileSize * 0 ,
        textureTileSize, textureTileSize));

    stoneFloorType1.loadFromFile (
        PATH_TEXTURE_FILE,sf::IntRect (
            textureTileSize * 0, textureTileSize * 1,
            textureTileSize, textureTileSize));

    stoneFloorType2.loadFromFile (
        PATH_TEXTURE_FILE,sf::IntRect (
            textureTileSize * 0, textureTileSize * 2,
            textureTileSize,textureTileSize));

    stoneWallType1.loadFromFile (
        PATH_TEXTURE_FILE,sf::IntRect (
            textureTileSize * 0, textureTileSize * 2,
            textureTileSize,textureTileSize));

    stoneWallType0.loadFromFile (
        PATH_TEXTURE_FILE,sf::IntRect (
            textureTileSize * 1, textureTileSize * 0,
            textureTileSize,textureTileSize));
    stoneWallType1.loadFromFile (
        PATH_TEXTURE_FILE,sf::IntRect (
            textureTileSize * 1, textureTileSize * 1,
            textureTileSize,textureTileSize));
    stoneWallType2.loadFromFile (
        PATH_TEXTURE_FILE,sf::IntRect (
            textureTileSize * 1, textureTileSize * 2,
            textureTileSize,textureTileSize));


}

void field::loadSprite () {
    sprite.setTexture(stoneFloorType1);
}

sf::Texture & field::getTextureChoice (short int length,short int width) {
    switch (fieldArrayCell [length] [width] [0]){
        
        //pasFloorType0
        case 11:
            return stoneFloorType0;
            break;
        //pasFloorType1
        case 12:
            return stoneFloorType1;
            break;
        //pasFloorType2
        case 13:
            return stoneFloorType2;
            break;
        
        case 31:
            return stoneWallType0;
            break;
        case 32:
            return stoneWallType1;
            break;
        case 33:
            return stoneWallType2;
        default:
            break;
    }
} 

// satart grid generation field
void field::startGridMazeGenerationField() {
    for (int i = 0; i < lengthField ; i++) {
        for (int j = 0; j < widthField; j++){
            // fast bit parity
            if (((i & 1) && (j & 1) ) && !((i == lengthField - 1) || (j == widthField - 1))) {
                fieldArrayCell [i][j][0] = emptyCell;
            } else {
                fieldArrayCell [i][j][0] = wallCell ;
            }
        }
    }
}

void field::mazeGenerationField () {
    // starting cell for path generation
    // cell start step of the algorithm
    cell curentCell;
    curentCell.inLength_x = 1;
    curentCell.inWidth_y = 1;

    std::vector <cell> cellStackWay ;

    // initialize the future move
    cell cellNeighborTarget ;
    // in generation, the starting cell is always a pass
    
    
    cellStack cellStackNeighbor;
    
    bool genNOTEnded = true; 

    while (genNOTEnded) {
        
        fieldArrayCell [ curentCell.inLength_x][curentCell.inWidth_y][0] = passageCell;
        cellStackNeighbor =  getNeighbor (&curentCell);

        if (cellStackNeighbor.size != 0) {
            // choose random
            int randNum = getRandomNumber (0, cellStackNeighbor.size-1);
            cellNeighborTarget = cellStackNeighbor.cells[randNum];
            removeWall (& curentCell, & cellNeighborTarget);
            // mark the cell on the field ad "current for rendering"
            fieldArrayCell
            [cellNeighborTarget.inLength_x][cellNeighborTarget.inWidth_y][0]= wallCell;

            //we save the current cell on the stack
            cellStackWay.push_back(curentCell);
            // replase curent cell whit Negivord Cell
            curentCell = cellNeighborTarget;

        } else {
            if (cellStackWay.size() > 0 ){
                //  if there are no more neighbors 
                // and the stack is not empty        
                curentCell = cellStackWay.at(cellStackWay.size()-1);
                cellStackWay.pop_back();
            } else {
                genNOTEnded = false;
            }
        }
    }
}



field::cellStack field::getNeighbor (cell * curentCell) {
    int distance {2};
    cell north = 
    { curentCell->inLength_x, curentCell->inWidth_y - distance };
    cell east = 
    { curentCell->inLength_x + distance, curentCell->inWidth_y };
    cell south = 
    { curentCell->inLength_x , curentCell->inWidth_y + distance };
    cell west = 
    { curentCell->inLength_x - distance, curentCell->inWidth_y };

    cell neighborCell[4] = { north, east, south, west } ;
    
    // initializean empty  the structure to return
    cellStack neighiborResult;

    neighiborResult.size = 0;
    neighiborResult.cells = new cell [4];  // ???? i am a alock mem
    int size{0} ; // temp length 

    for (int i = 0; i < 4; i++) {
        if (neighborCell[i].inLength_x > 0 && neighborCell[i].inLength_x < lengthField - 1 
        && neighborCell[i].inWidth_y > 0 && neighborCell[i].inWidth_y < widthField - 1) {
            char mazeCellCurrent {0};
            // see the value of the neighbor
            mazeCellCurrent =  fieldArrayCell [neighborCell[i].inLength_x][neighborCell[i].inWidth_y][0];

            // if cell not a wall and visited
            // check for a non-generated cell
            if (mazeCellCurrent != passageCell && 
            mazeCellCurrent != wallCell ) {
                neighiborResult.cells[size] = neighborCell[i];
                size ++;
            }
        }
    }
    neighiborResult.size = size;
    return neighiborResult; 

}

void field::removeWall (cell * first, cell * last) { 
    int xDifference = (first->inLength_x + last->inLength_x) ;
    int yDifference = (first->inWidth_y + last->inWidth_y) ;
    int addX = xDifference / 2;
    int addY = yDifference / 2;
    //the midpoint is calculated using the standard mean algorithm
    fieldArrayCell [addX][addY][0] = passageCell;

}

void field::randomizationCellType () {
    for ( int i = 0 ; i < lengthField ; i++) {
        for ( int j = 0; j < widthField ; j++) {
            
            fieldArrayCell [i] [j] [0] += getRandomNumber(1,3);

        }
    }
}