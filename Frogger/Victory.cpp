#include "Victory.h"


Victory::Victory()
	: Sprite(VICTORY_PATH)
{
	
}

Victory::Victory(int width, int height)
	: Sprite(VICTORY_PATH)
	, width(width)
	, height(height)
{
	rect = Rectangle(GetX(), GetY(), width, height);
}

Victory::~Victory()
{
}
