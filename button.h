//This is a class for a button, and pushing it. For our purposes, the whole
//screen will be a button but perhaps individual buttons will come in handy for menu options etc.
#ifndef BUTTON_H
#define BUTTON_H
#include <SDL/SDL_image.h>
#include <iostream>
#include <string>

using namespace std;

class Button {
	private:
		SDL_Rect rectangle; // the outline of the butotn;
		
		SDL_Rect* clip; // the visible button on screen
	public:
		//constructor:
		Button (int x, int y, int w, int h );
		void handle_events();  //These last two functions were 
					// taken mostly from teh ttutorial
		void show(); //shows the button on screen	
};


