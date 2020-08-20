.PHONY: bild all clean analyze

CC = clang++

COMPILE_FLAG = -c -Wall 

vpath %.cpp src   



DEBAG_FLAF =

SFML_INCLUDE = -lsfml-graphics -lsfml-window -lsfml-system

Game : main.o field.o resources.o character.o
	$(CC) $^ -o $@ $(SFML_INCLUDE)

main.o : main.cpp 
	$(CC) $(COMPILE_FLAG) $^ 
field.o : field.cpp
	$(CC) $(COMPILE_FLAG) $^ 
character.o: character.cpp
	$(CC) $(COMPILE_FLAG) $^
resources.o : resources.cpp
	$(CC) $(COMPILE_FLAG) $^ 


clean:
	rm -f *.o 

analyze : main.cpp field.cpp character.cpp  resources.cpp 
	clang-10 --analyze --analyzer-output text $^
	cppcheck -q -j4 --enable=performance,portability,warning,style $^
