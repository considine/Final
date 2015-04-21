#include "bird.h" 
#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

bird::bird() { //constructor
	Baccelerator = false;
	speed = 0;
}


void bird::setInitial(int x, int y, int L, int W) {
	accelerator = 0;
	screenPosX = x;
	screenPosY = y;
	sizeL = L;
	sizeW = W;
}
	
void bird::jump() {
	accelerator = -10; // no more falling!
	screenPosY -= screenL/10;
	speed = 1;
}

void bird::fall() {
	screenPosY += 1;
	screenPosY += accelerator/30;
	//set the speed based on accelerator   value:
	if (accelerator < 10)  speed =1;  
	else if (accelerator<20) speed =0;   //this is our layout of the 
	else if (accelerator<23) speed =2;   //proper bird based on spot
	else if (accelerator<26) speed =3;
	else if (accelerator>26) speed =4;
	if (accelerator<60&&Baccelerator) accelerator++;
	cout<<"sdfds"<<endl;
}

int bird::getHeight() {
	return screenPosY;
}

void bird::littlejump() {
	screenPosY -=1;
}

void bird::accelerate() {
	Baccelerator = true;
}

int bird::getAccelerator() {
	return speed;
}

void bird::resetSpeed() {
	speed = 0;
}

int bird::getsizeL() {
	return sizeL;
}

int bird::getsizeW() {
	return sizeW;
}


void bird::setScreen(int width, int length){
	screenL = length;
	screenW = width;
}
