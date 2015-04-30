#ifndef BIRD_H
#define BIRD_H

class bird { 
	public:
		bird();  //bird constructor. flalbacks = screen h/w
		
		void jump(); //y position moves up(down) ten
		void fall(); // yposition moves down (up) one		
		void littlejump(); //before game starts, slgiht movement
		int getHeight(); //retruns the height of the bird
		void setInitial(int, int, int, int); //sets initial height and width
		void accelerate(); //switches accelerator on
		int getAccelerator(); //returns value of accelerator
		void resetSpeed(); //sets the birds position to normal
		int getsizeL(); //returns the birds length
		int getsizeW(); //returns the birds width
		void setScreen(int=500, int=500); //sets the screen size for proper communitcation

	private:
		bool Baccelerator;  //'Boolean accelerator' indicates falling
		int screenPosX; //position relative to the screen always in center
		int screenPosY; //position relative to the screen (y)
		int height;	
		int width;  // the relative sizes of the bird should be 50
		int accelerator;
		int speed; //how fast the bird is falling
		int sizeL; //bird length
		int sizeW; //bird width
		int screenL;  //Length & Width
		int screenW;   //of the screen
};

#endif
