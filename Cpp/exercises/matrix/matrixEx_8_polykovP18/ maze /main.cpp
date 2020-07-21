/* Generating and solving a maze using the graph depth-first search method.
 *
 *+++  1) generating a lattice
 *      1.1) start position, start cell is marked as "visited"
 *      1.2) not all cells have the "visited" status?
 *          IF
 *          1.2.1) If the current cell has unvisited neighbors
 *            -  Poke the current cell onto the stack
 *            - Select a random cell from adjacent
 *            - Remove the wall between the current cell and the selected
 *            - Make the selected cell current and mark it as visited.
 *           Else IF
 *           1.2.2 ) Otherwise, if the stack is not empty
 *            - Pop a cell off the stack
 *            - Make it current
 *          Else
 *          1.2.3 ) select a random cell and mark it as visited
 *          (If this condition is met, then an isolated area has appeared.
 */


#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "maze.h"

int main() {
    // init random
    srand(static_cast<unsigned int>(time(NULL)));

    // window dimensions
    int screenWidth {800} ; // all screan!
    int screenHeight {600} ; // all screan !

    // generation field size
    int fieldWidth  = screenWidth - screenWidth / 6 ;
    int fieldHeight = screenHeight - screenHeight / 6 ;

    // Create the main window
    sf::RenderWindow app(sf::VideoMode(screenWidth, screenHeight), "SFML window");

    app.setFramerateLimit (2) ;
    app.setPosition (sf::Vector2i(10,10));

    int cellSize {25} ;
    // the number of cells is generated automatically
    int cellNumWidth = fieldWidth / cellSize ;
    int cellNumHeight = fieldHeight / cellSize  ;
    //generation logical arrays
    char **arr1 = constructorArr (cellNumWidth, cellNumHeight);

    std::vector <cell>  cellsStackWay;
    cell curentCell;
    curentCell.x = 1;
    curentCell.y = 1;

    cell finishCell;
    if ( arr1 [cellNumWidth - 2][cellNumHeight - 2] == g_emptyCell ) {
        finishCell.x =  cellNumWidth - 2 ;
        finishCell.y = cellNumHeight - 2 ;
    }

    // initialization cell
    sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
    startGridGen (arr1, cellNumWidth , cellNumHeight) ;

    //
    bool genEnded {false};
	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event)) {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }

        if ( !(genEnded)) {
            mazeGenStep (arr1, &cellsStackWay, &curentCell , cellNumWidth , cellNumHeight, &genEnded  );
        }
        /*if ( genEnded ) {

        } */

        //void mazeGenStep (char **arr, std::vector <cell> * cellStackWay ,
        // cell  curentCell ,int widthField ,int heightField );
        // Clear screen
        app.clear();

        drowGrid (cellSize, arr1, cellNumWidth , cellNumHeight, &app , &cell ) ;



        // Update the window
        app.display();

    }

    destructorArr ( arr1, cellNumWidth );

    return EXIT_SUCCESS;
}
