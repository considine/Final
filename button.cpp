#include "button.h"



Button::Button( int x, int y, int w, int h )
{
	//Set the size of the button
	rectanlge.x = x;
	rectangle.y = y;
	rectangle.w = w;
	rectangle.h = h;

	clip = &clips[ CLIP_MOUSEOUT ];
}


void Button::show () { // the button display functinon
	apply_surface( box.x, box.y, buttonSheet, screen, clip );
}
