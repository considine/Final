#include "pipes.h"
#include <iostream>
#include <time.h>  //to initialize srand
#include <stdlib.h> //for frand functions
using namespace std;


pipes::pipes()
{
}

int pipes::randomHeight(int oldpipe) {
	srand(time(NULL)); // initialize seed;
	int difference = rand() % 2*change - change;  //this is where the gap may land;
	return gety(oldpipe) + difference;
}

int pipes::getGap() 
{
	return gap;
}

int pipes::getx(int num) {
	return xPositions[num];
}

int pipes::gety(int num) {
        return yPositions[num];
}

int pipes::setx(int num, int num2) {
        xPositions[num] = num2;
}

int pipes::sety(int num, int num2) {
        yPositions[num] = num2;
}

void pipes::movetime(){
	movevariable++;
	if ((getmovevariable() %1) != 0) return;
	int newx;
	for (int i =0; i<3; i++) {
	srand(time(NULL));
		if (getx(i) < -10) {
			setx(i, screenW*1.2);
			sety(i, rand() % screenH/2 + screenH/4);
		}
		newx = getx(i);
		setx(i, --newx); //iterate pipes oner pixel
	}
}

int pipes::getmovevariable() {
	return movevariable;
}


void pipes::setscreen(int width, int height) {
	screenH = height;
	screenW = width; // now we know
	gap = screenH/4;
        change = 2*gap;
        movevariable =0;

	srand(time(NULL));
        for (int i=0; i<3; i++) {
                sety(i, screenH/2); //just to initialize
                setx (i, screenW + i*screenW/2);
        }

}
