#include <iostream>
#ifndef SCORE_H
#define SCORE_H
class Score {
	public:
		void addScore;		//increments score
		int getScore;		//returns score
		int setHigh;		//sets high score text file to contain highest score (new or old)
	private:
		int score;		//current score
		int highScore;		//high score read in from high score text file
}

#endif
