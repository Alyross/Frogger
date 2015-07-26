#pragma once
#include "Sprite.h"

#define VICTORY_PATH "Images/Victory.png"

class Victory :
	public Sprite
{
public:
	Victory();
	Victory(int width, int height);
	~Victory();

	Rectangle GetRect(){ return rect; }

private:

	int width;
	int height;

	Rectangle rect;
};

