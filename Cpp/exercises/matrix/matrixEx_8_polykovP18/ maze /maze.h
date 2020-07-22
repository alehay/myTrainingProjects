#ifndef MAZE_H_INCLUDED
#define MAZE_H_INCLUDED

struct cell {
     int x;
     int y;
};


int getRandomNumber(int min, int max);
char ** constructorArr (int width, int height);
void destructorArr (char **arr, int width);
void startGridGen (char **arr, int width, int height);
void drowGrid (int cellSize, char **arr, int cellNumWidth, int cellNumHeight,
                sf::RenderWindow * app, sf::RectangleShape * rect ) ;


void removeWall (cell first , cell last, char ** arr);

void mazeGenStep (char **arr, std::vector <cell> * cellStackWay , cell  * curentCell ,int widthField ,int heightField , bool * genEnded );


void mazeSolution (char **arr, std::vector <cell> * cellStackSolution , cell *  curentCell ,
                                                    int widthField , int heightField , cell * finishCell,  bool * sulutionEnded ); 
const char g_emptyCell = static_cast <char> (255) ;
const char g_wallCell = static_cast <char> (1) ;
const char g_visitedCell = static_cast <char> (3);
const char g_currentCell = static_cast <char> (5);
const char g_visitedSulution =  static_cast <char> (7) ;
const char g_out =  static_cast <char> (10) ;
const char g_wrong = static_cast <char> (12);




/*
typedef struct cellStack {
  cell * cells;
  unsigned int size {0};
}cellStack;
*/

struct cellStack {
  cell * cells;
  int size {0};

};



#endif // MAZE_H_INCLUDED
