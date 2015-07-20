#include "Frog.h"

const float Frog::speed = 0.5f;

Frog::Frog()
	: Sprite(FROG_PATH)
	, currentPos(2.f)
{

}


Frog::~Frog()
{
}

void Frog::Update()
{
	//SetPosition(GetX(), currentPos += speed);

	//if (mEvent->key.keysym.sym == SDLK_ESCAPE)
} 