// Game.h
//

#ifndef GAME_H
#define GAME_H

class Game {

	public:
		Game();
		void Play();
		int Collision();	
		void Menu();

	private:
		Bird myBird;
		Score myScore;	
};

#endif
