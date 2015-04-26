#OBJS specifies which files to compile as part of the project
OBJS =  pipes.cpp bird.cpp main.cpp graphics.cpp

#LINKER_FLAGS
LINKER_FLAGS = -lSDL2

#OBJ_NAME speciies name of executable
OBJ_NAME = main


all: $(OBJ_NAME)
	g++ $(OBJS) $(LINKER_FLAGS) -o $(OBJ_NAME)


clean: 
	rm *.o main
