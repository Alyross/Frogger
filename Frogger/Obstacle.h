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
};

