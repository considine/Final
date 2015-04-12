#include <iostream>
#include <fstream>
#include "Score.h"

using namespace std;

Score::Score() {
	score=0;				//set initial score to 0

	//read in high score from text file
	ifstream highText;
	highText.open("highscore.txt");
	if (highText) {				//if high score text file exists
		infile>>highScore;		//read in high score from file & store as highScore
		highText.close();
	} else {				//if high score text file does not exist
		highScore=-1;			//set high score to -1
	}
}

int Score::getScore {				//returns score
	return score;
}

void Score::addScore {				//increments score
	score++;
}

void Score::setHigh {				//if current high score is greater than old high score
	if (score>highScore)
		ofstream hightext;		//write new high score to high score text file
		hightext.open ("highscore.txt");
		hightext << score;
		hightext.close();
	}
}

