#ifndef BIRD_H
#define BIRD_H


class bird { 
	public:
		bird(int = 350, int =450); //construcotr with width and height fallbakck
		
	private:
		int screenPosX; //position relative to the screen (x)
		int screenPosY; //position relative to the screen (y)
		int height;	
		int width;  // the relative sizes of the bird
};

#endif
