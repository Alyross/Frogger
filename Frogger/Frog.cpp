#include "Frog.h"

const float Frog::speed = 0.5f;

Frog::Frog()
	: Sprite(FROG_PATH)
	, currentPos(0.f)
{
}


Frog::~Frog()
{
}

void Frog::Update()
{
	//currentPos += speed;

	dstRect->x = currentPos;
} 