#include "bird.h" 
#include <SDL2/SDL.h>


bird::bird() { //constructor
}


void bird::setInitial(int x, int y) {
	screenPosX = x;
	screenPosY = y;
}
	
void bird::jump() {
	screenPosY -= 40;
}

void bird::fall() {
	screenPosY += 1;
}

int bird::getHeight() {
	return screenPosY;
}
