TARGET = bild

.PHONY:bild all clean install uninstall

CC = clang++

COMPILE_FLAG = 



DEBAG_FLAF =

SFML_INCLUDE = -lsfml-graphics -lsfml-window -lsfml-system

mazeGen: main.o maze.o text.o
	$(CC) main.o maze.o text.o -o $@ $(SFML_INCLUDE)

main.o : main.cpp
	$(CC) -c main.cpp  $(SFML_INCLUDE) 
maze.o : maze.cpp
	$(CC) -c maze.cpp $(SFML_INCLUDE)
text.o : text.cpp
	$(CC) -c text.cpp $(SFML_INCLUDE)

clean:
	rm -f *.o 

