TARGET = bild

.PHONY:bild all clean install uninstall

CC = clang++

COMPILE_FLAG = -c



DEBAG_FLAF =

SFML_INCLUDE = -lsfml-graphics -lsfml-window -lsfml-system

mazeGen: main.o maze.o text.o
	$(CC) main.o maze.o text.o -o $@ $(SFML_INCLUDE)

main.o : main.cpp
	$(CC) $(COMPILE_FLAG) main.cpp  
maze.o : maze.cpp
	$(CC) $(COMPILE_FLAG) maze.cpp 
text.o : text.cpp
	$(CC) $(COMPILE_FLAG) text.cpp 

clean:
	rm -f *.o 

