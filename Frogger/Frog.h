#pragma once
#include "Sprite.h"

#define FROG_PATH "Images/Frog.png"

class Frog :
	public Sprite
{
public:
	Frog();
	~Frog();

	void Update();
	Rectangle GetRect(){ return rect; }

private:
	float currentPos;
	Rectangle rect;

	static const float speed;
};

