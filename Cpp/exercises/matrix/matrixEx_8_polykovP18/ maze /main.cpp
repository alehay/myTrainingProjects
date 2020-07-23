/* Generating and solving a maze using the graph depth-first search method.
 *
 *  1) generating a lattice
 *      1.1) start position, start cell is marked as "visited"
 *      1.2) not all cells have the "visited" status?
 *          IF
 *           1.2.1) If the current cell has unvisited neighbors
 *            -  Poke the current cell onto the stack
 *            - Select a random cell from adjacent
 *            - Remove the wall between the current cell and the selected
 *            - Make the selected cell current and mark it as visited.
 *         Else IF
 *           1.2.2 ) Otherwise, if the stack is not empty
 *            - Pop a cell off the stack
 *            - Make it current
 *          Else
 *           1.2.3 ) select a random cell and mark it as visited
 *           (If this condition is met, then an isolated area has appeared.
 */

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include "maze.h"
#include "text.h"



int main() {
    // init random
    srand(static_cast<unsigned int>(time(NULL)));
    // window dimensions
    int screenWidth {1600} ; // all screan!
    int screenHeight {900} ; // all screan !

    // generation field size
    int fieldWidth  = screenWidth - screenWidth / 5 ;
    int fieldHeight = screenHeight; //- screenHeight / 10 ;

    // Create the main window
    sf::RenderWindow app(sf::VideoMode(screenWidth, screenHeight), "maze generation");

    app.setFramerateLimit (25) ;
    app.setPosition (sf::Vector2i(10,10));

    sf::Text rightLab ;
    sf::Font font;
    if ( !font.loadFromFile("font.ttf")) {
        std::cout << "font_dont_loading"<< std::endl;
    }
    // counter for rendering 
    // the number of all generated cell 
    int couterCellGen {0};
    int couterCellGenTemp{0};
    //the number of all cells in the path
    int couterCellPass {0};
    //cells discarded by the algorithm as false 
    int couterCellFalse {0};

    int cellSize {13} ;
    // the number of cells is generated automatically
    int cellNumWidth = fieldWidth / cellSize ;
    int cellNumHeight = fieldHeight / cellSize  ;
    //generation logical arrays
    char **arr1 = constructorArr (cellNumWidth, cellNumHeight);


    // create a cell storage stack
    std::vector <cell>  cellsStackWay;
    cell curentCell;
    curentCell.x = 1;
    curentCell.y = 1;
    // stratr cell
    cell curentCellSul;
    curentCellSul.x = 1;
    curentCellSul.y = 1;
    // finish cell
    cell finishCell;
    finishCell.x =  cellNumWidth - 3 ;
    finishCell.y = cellNumHeight - 3 ;

    // initialization  render cell
    sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
    startGridGen (arr1, cellNumWidth , cellNumHeight) ;

    // cycle switch
    bool genEnded {false};
    bool sulutionEnded {false};
	// Start the game loop
    while (app.isOpen()) {
        // Process events
        sf::Event event;
        while (app.pollEvent(event)) {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }

        for (int i = 0 ; i < 1 ; i++) {
            if ( !(genEnded)) {
                //mazeGenStep (arr1, &cellsStackWay, &curentCell , cellNumWidth ,
                // cellNumHeight, &genEnded , & cellsNum );
                mazeGenStep (arr1, &cellsStackWay, &curentCell , cellNumWidth , cellNumHeight, &genEnded );
            }
            if ( genEnded && !(sulutionEnded) ) {
                arr1 [finishCell.x][finishCell.y] = g_out;
                mazeSolution (arr1, &cellsStackWay, &curentCellSul,  cellNumWidth , cellNumHeight, &finishCell, &sulutionEnded) ;

            }
        }

        app.clear();
        drowGrid (cellSize, arr1, cellNumWidth , cellNumHeight, &app , &cell ,
                     &couterCellGen , &couterCellPass , &couterCellFalse ) ;
        if (!(genEnded)) {
            couterCellGenTemp = couterCellGen ;
        }
       
        laibleSettings( fieldWidth, &rightLab , &font , &app, 
                    std::to_string(couterCellGenTemp), std::to_string(couterCellPass), std::to_string(couterCellFalse) );
       
        //app.draw(rightLab);
        // Update the window
        app.display();
    }

    destructorArr ( arr1, cellNumWidth );
    return EXIT_SUCCESS;
}
