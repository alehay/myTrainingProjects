#include <SFML/Graphics.hpp>
#include "header/field.h"
#include "header/resources.h"
#include <ctime> // для функции time()
#include "header/gamecharacter.h"

int main()

{
    sf::Clock clock;
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(1200, 800), "SFML window");
    app.setFramerateLimit (60) ;
    // Load a sprite to display
    //sf::Texture texture;

    //if (!texture.loadFromFile("texture/textureBase.png"))
    //    return EXIT_FAILURE;
    //sf::Sprite sprite(texture);

    srand(static_cast<unsigned int>(time(0)));


    field *myGameField = new field(25,15,1);
    GameCharacter Demon (20,20);
    int timeRatio {1000};
	// Start the game loop
    while (app.isOpen())
    {   
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart(); //reload time
        
        time = time / timeRatio; //game speed
        
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                Demon.movWest(time);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                Demon.movEast(time);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                Demon.movNorth(time);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                Demon.movSouth(time);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) &&
                (timeRatio < 2500)){
                timeRatio += 50;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && 
                (timeRatio > 500)){
                timeRatio -=50;
            }
        //}

        // Clear screen
        app.clear();

        // Draw the sprite
       // app.draw(sprite);
        myGameField->show(& app);
        Demon.show(& app, time);
        // Update the window
        app.display();
    }
    delete myGameField;

    return EXIT_SUCCESS;
}
