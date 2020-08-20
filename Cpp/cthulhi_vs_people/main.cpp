#include <SFML/Graphics.hpp>
#include "header/field.h"
#include "header/resources.h"
#include <ctime> // для функции time()


int main()

{
    sf::Clock clock;
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(1200, 800), "SFML window");
    app.setFramerateLimit (1) ;
    // Load a sprite to display
    //sf::Texture texture;

    //if (!texture.loadFromFile("texture/textureBase.png"))
    //    return EXIT_FAILURE;
    //sf::Sprite sprite(texture);

    srand(static_cast<unsigned int>(time(0)));


    field *myGameField = new field(25,15,1);
	// Start the game loop
    while (app.isOpen())
    {   
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart(); //перезагружает время
        time = time/800; //скорость игры
        
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }

        // Clear screen
        app.clear();

        // Draw the sprite
       // app.draw(sprite);
        myGameField->show(& app);

        // Update the window
        app.display();
    }
    delete myGameField;

    return EXIT_SUCCESS;
}
