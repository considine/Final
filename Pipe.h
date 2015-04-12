#include <iostream>
#ifndef PIPE_H
#define PIPE_H

class Pipe {
	public:
		Pipe();
		int getX1();
		int getY1();
		int getX2();
		int getY2();
		void setX2();
		void setY2();
		double getVel();
		int getGap();
		int isDead();
	private:
		int xpos1;
		int ypos1;
		double xvelocity;
		int gapSize;
		int xpos2;
		int ypos2;
		int width;
}

#endif
