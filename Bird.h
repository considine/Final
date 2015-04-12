// Bird.h
//

#ifndef BIRD_H
#define BIRD_H
class Bird {

	public:
		Bird();
		int isDead();
		void jump();
		int getX();
		int getY();
		void falling();
	
	private:
		int xpos;
		int ypos;
		double velocity;
		double acceleration;
		SDL_Texture* birdTexture;	
};


#endif
