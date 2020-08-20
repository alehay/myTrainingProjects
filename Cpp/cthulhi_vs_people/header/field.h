

#ifndef FIELD_H
#define FIELD_H
#include <SFML/Graphics.hpp>
#include <vector>

class field
{
    public:
        //  fieldArrayCell [lengtht] [widht] [depth] 
        field(short int length, short int width, short int depth);
        virtual ~field();
        // RENDER field
        void show (sf::RenderWindow * app) ;
    
    private:

        ////////////////// TEXTURE ///////////////////
        //title size 
        const int textureTileSize {48}; 
        const std::string PATH_TEXTURE_FILE {"texture/textureDEBAG.png"} ;
        
        // texture pack load
        sf::Texture baseTexture;
        sf::Texture stoneFloorType0;
        sf::Texture stoneFloorType1;
        sf::Texture stoneFloorType2;
        sf::Texture stoneWallType0;
        sf::Texture stoneWallType1;
        sf::Texture stoneWallType2;
        
        // texture sptrite
        sf::Sprite sprite;

        void loadTexturePack0 ();
        void loadSprite ();

        sf::Texture & getTextureChoice (short int length, short int width);



        ////////////////////// FIELD CELL STATE /////////////////
        // game field statde
        //  fieldArrayCell [lengtht] [widht] [deph] 
        char *** fieldArrayCell;

        //game field parametrs
        short int lengthField;
        short int widthField;
        short int depthField;

        // Type cell state
        const char emptyCell = static_cast <char> (1);
        const char passageCell = static_cast<char>(10);
        const char pasFloorType0 = static_cast <char> (11);
        const char pasFloorType1 = static_cast <char> (12);
        const char pasFloorType2 = static_cast <char> (13);
        
        const char wallCell = static_cast<char>(30);
        const char wallType0 = static_cast <char> (31);
        const char wallType1 = static_cast <char> (32);
        const char wallType2 = static_cast <char> (33);



        // struct cell
        // compact storage of location 
        //data in the generation algorithm
        struct cell {
            int inLength_x {1};
            int inWidth_y {1};
            int inDepth_z {0};
        };

        struct cellStack {
            unsigned int size;
            cell * cells;
        };

        // working on the array 
        //of the playing field state
        void startGridMazeGenerationField();
        void mazeGenerationField();
        cellStack getNeighbor  (cell * curentCell);
        void removeWall (cell * first, cell * last) ;
        void randomizationCellType ();
};

#endif // FIELD_H
