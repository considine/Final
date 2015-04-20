#ifndef BIRD_H
#define BIRD_H


class bird { 
	public:
		bird();  //bird constructor. flalbacks = screen h/w
		void jump(); //y position moves up(down) ten
		void fall(); // yposition moves down (up) one		
		int getHeight(); //retruns the height of the bird
		void setInitial(int, int); //sets initial height and width
	private:
		int screenPosX; //position relative to the screen always in center
		int screenPosY; //position relative to the screen (y)
		int height;	
		int width;  // the relative sizes of the bird should be 50
		
};

#endif
