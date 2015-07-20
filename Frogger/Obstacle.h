#pragma once
#include "Sprite.h"
class Obstacle :
	public Sprite
{
public:
	Obstacle();
	virtual ~Obstacle();

protected:
	short maxWidth;
	short minWidth;

	//float speed;
	//int direction;
	//int edge;
};

