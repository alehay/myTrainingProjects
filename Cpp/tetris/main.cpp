#include <SFML/Graphics.hpp>
#include <time.h>

const int oneBlockSizePx = 32;
const int heightPlayingField = 30;
const int widthPlayingField = 20;

int field[heightPlayingField][widthPlayingField] = { 0 } ;

// tetramino tetris figures
int figures[7][4] =  {
    {1,3,5,7}, // I - 0
	{2,4,5,7}, // S - 1
	{3,5,4,6}, // Z - 2
	{3,5,4,7}, // T - 3
	{2,3,5,7}, // L - 4
	{3,5,7,6}, // J - 5
	{2,3,4,5}, // O - 6
};
////////////////////////////////////////////////////////////////
/* drawing:
two-dimensional array which contains
information which squares are filled
teramino S examl
*    0   1   i

 0   0   1

 1   2*  3

 2   4*  5*

 3   6   7*

 n

 *for (int i = 0; i < 4; i++) {
 *         a[i].x = figures[n][i] % 2;
 *         a[i].y = figures[n][i] / 2;
 *
*/ ///////////////////////////////////////////////////////////


// initialization tetramino atribut  Color and Coordinat
struct Point
{
    int x,y ;
} ;

Point coordinat[4];
Point tempCordinat[4];
int colorNum = 1 ;

//check for going abroad 
bool check () {
    for (int i = 0; i < 4; i++) {
        if (coordinat[i].x < 0 || coordinat[i].x >= widthPlayingField  ||
        coordinat[i].y >= heightPlayingField ) {
            return false;
        } else if ( field[coordinat[i].y] [coordinat[i].x] ) {
            return false;
        }
    }
    return true;
}

int main() {
    srand(time(0));

    // Create the main window
    //sf::RenderWindow tetrisWindow(sf::VideoMode(640, 960), "The Game!");
    sf::RenderWindow tetrisWindow(sf::VideoMode(widthPlayingField * oneBlockSizePx, heightPlayingField * oneBlockSizePx), "The Game!");

    // loading texture
    sf::Texture blockTexture;
    blockTexture.loadFromFile("/home/alehay/cod_projeckt/Tetris/tetris/rect182.png");

    // loading  block sprite tetramino 
    sf::Sprite blockSprite(blockTexture);

    // cut texture
    blockSprite.setTextureRect( sf::IntRect (0,0, oneBlockSizePx, oneBlockSizePx));

    //Time vareble for delay
    float timer = 0.f;
    float delay = 0.4;

    // loading Clock ( for timer)
    sf::Clock clock;

    // start game tetramino generator
    bool beginGame = true;

    // Start the GAME LOOP
    while (tetrisWindow.isOpen()) {
        float time;
        time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        // Process events
        int dX = 0;
        bool rotate = false ;
        int n = rand() % 7 ;
        sf::Event event;

        while (tetrisWindow.pollEvent(event)) {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                tetrisWindow.close();

            if (event.type == sf::Event::KeyPressed) {

            } else if (event.key.code == sf::Keyboard::Left) {
                dX = -1;
            } else if (event.key.code == sf::Keyboard::Right) {
                dX = 1 ;
            } else if (event.key.code == sf::Keyboard::Up) {
            rotate = true;
            }
        }

        // press key down , accelerate
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            delay = 0.05;
        }

        //applying coordinates horizontal move
        for (int i = 0; i < 4; i++) {
            tempCordinat[i] = coordinat[i];
            coordinat[i].x += dX;
        }

        //if we went abroad, we return the old coordinates
        // undo horizontal move
        if (!check () ) {
            for (int i = 0; i < 4; i++)
            coordinat [i] = tempCordinat [i];
        }
        
        /*
        *    X = x_0 + (x − x_0) * cos⁡(a) − (y − y_0 ) * sin⁡(a);
        *    Y = y_0 + (y − y_0) * cos⁡(a) + (x − x_0 ) * sin⁡(a);
        *    sin (90) = 1 ; cos (90) = 0
        *    X = x_0 − (y − y_0);
        *    Y = y_0 + (x − x_0);
        */
        //rotation
        if (rotate) {
            Point origin = coordinat[1]; // centr rotate
            for (int i = 0; i < 4 ; i++ ) {
                int x = coordinat[i].y - origin.y; // y - y0
                int y = coordinat[i].x - origin.x; // x - x0
                coordinat[i].x = origin.x - x; // x_0 - (y - y0)
                coordinat[i].y = origin.y + y ; //y_0 + (x - x_0) 
            }
        }

        if (!check () ) {
            for (int i = 0; i < 4; i++)
            coordinat [i] = tempCordinat [i];
        }

        // tretramino  tic tac
        // move down
        if (timer > delay) {
            for (int i = 0; i < 4; i ++) {
                tempCordinat[i] = coordinat[i] ;
                coordinat[i].y += 1;
            }
            
            if (!check()) {
                // save tetrimino on the field
                // tetramino stoped 
                for (int i = 0 ; i < 4 ; i++) {
                    field [tempCordinat[i].y] [tempCordinat[i].x] = colorNum;
                }
                
                // generate new tetramino
                colorNum = 1 + rand() % 7;
                n = rand () % 7;
                for (int i = 0 ; i < 4; i ++) {
                    coordinat[i].x = figures[n][i] % 2;
                    coordinat[i].y = figures[n][i] / 2;
                } 
            }           
            timer = 0;
        }

        //remove the filling line
        int k = heightPlayingField - 1;
        for (int i = heightPlayingField - 1; i > 0; i--) {
            int count = 0;
            for (int j = 0; j < widthPlayingField; j++) {
                if (field[i][j]) {
                    count++;
                }
                field[k][j] = field[i][j];
                }
                if (count < widthPlayingField) {
                    k--;
                }
        }
        //first tetramino
        // works only 1 time at the beginning of the game
        if (beginGame) {
            beginGame = false ;
            n = rand() % 7 ;
            for (int i = 0 ; i < 4 ; i++) {
                coordinat[i].x = figures[n][i] % 2;
                coordinat[i].y = figures[n][i] / 2;
            }
        }
        // Clear screen
        tetrisWindow.clear(sf::Color::White);
        for(int i = 0; i < heightPlayingField ; i++) {
            for ( int j = 0 ; j < widthPlayingField ; j++) {
                if (field[i][j] == 0 ) {
                    continue;
                }
                // color tetramino that stand
                blockSprite.setTextureRect(sf::IntRect(field[i][j] * oneBlockSizePx, 0 ,
                                                                    oneBlockSizePx, oneBlockSizePx) );

            //    blockSprite.setPosition(j * oneBlockSizePx, i * oneBlockSizePx);
                tetrisWindow.draw(blockSprite);
            }

        }
        // uv texture coordinates ????
        for ( int i = 0; i < 4; i++) {
            blockSprite.setTextureRect(sf::IntRect(colorNum * oneBlockSizePx, 0 ,
                                                            oneBlockSizePx, oneBlockSizePx) );

            // give position evry tetramino bloc
            //Tetrimino that fly 
            blockSprite.setPosition(coordinat[i].x * oneBlockSizePx ,
                                    coordinat[i].y * oneBlockSizePx);
            tetrisWindow.draw(blockSprite);
        }

        // reload varible after move
        dX = 0;
        rotate = false;
        delay = 0.4;
        tetrisWindow.draw(blockSprite);

        // Update the window
        tetrisWindow.display();
    }

    return EXIT_SUCCESS;
}
