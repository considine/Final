#include <iostream>
#include "Pipe.h"

using namespace std;

Pipe::Pipe() {
	xpos1=360;
	xpos2=360;
	//ypos1=????
	ypos2=ypos1+gapSize;
}

int Pipe::getX1() {
	return xpos1;
}

int Pipe::getY1() {
	return ypos1;
}

int Pipe::getX2() {
	return xpos2;
}

int Pipe::getY2() {
	return ypos2;
}
double Pipe::getVel() {
	return xvelocity;
}

int Pipe::getGap() {
	return gapSize;
}

void Pipe::setX2() {
	xpos2=xpos1;
}

void Pipe::setY2() {
	ypos2=ypos1+gapSize;
}

int isDead() {
	if (xpos1<(-1*gapSize))
		return 1;
	else
		return 0;
}

}
