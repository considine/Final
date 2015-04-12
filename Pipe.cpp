#include <iostream>
#include <iostream>
#include "Pipe.h"

using namespace std;

Pipe::Pipe() {

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

}
