all: main

main: main.o Bird.o Pipe.o Game.o Score.o
	g++ main.o Bird.o Pipe.o Game.o Score.o -lSDL2 -o Flappy

main.o: main.cpp
	g++ -c main.cpp
Bird.o: Bird.cpp
	g++ -c Bird.cpp
Pipe.o: Pipe.cpp
	g++ -c Pipe.cpp
Score.o: Score.cpp
	g++ -c Score.cpp

clean:
	rm *.o Flappy
