#pragma once
#include "Sprite.h"

#define FROG_PATH "Images/Frog.psd"

class Frog :
	public Sprite
{
public:
	Frog();
	~Frog();

	void Update();

	float currentPos;
	static const float speed;
};

