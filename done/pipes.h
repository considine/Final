#ifndef PIPES_H
#define PIPES_H


class pipes {
	public:
		pipes(); //constructor
		void drawPipe(); //illustrates the pipes
		int randomHeight(int); //gets a random height for the pipes
		int getGap();
		int getx(int); //get the x position of any of the three pipes
		int gety(int); //get the x position of any of the three pipes
		int setx(int, int); //set the x position of any of the three pipes
		int getmovevariable(); //get the variable .. see below
		int sety(int, int); //set the x position of any of the three pipes
		void movetime();
		void setscreen(int = 500, int = 500); //sets the screen dimensions
			
	private:
		int gap;  //distance between two pipes
		int xPositions[3]; //array of three x positoins
		int yPositions[3]; //array of three y positionsi
		int speed; //changes per level
		int change; //the change in levels, per difficulty
		int movevariable; // iterator for pipe movement
		int screenH;  //screen height, useful to have
		int screenW; //screen width '''
};

#endif
