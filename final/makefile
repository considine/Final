all: main

main: main.o graphics.o pipes.o bird.o 
	g++ main.o graphics.o pipes.o bird.o -lSDL2 -o main

main.o: main.cpp
	g++ -c main.cpp


graphics.o: graphics.cpp
	g++ -c graphics.cpp

pipes.o: pipes.cpp
	g++ -c pipes.cpp

bird.o: bird.cpp
	g++ -c bird.cpp

clean: 
	rm *.o main

	
