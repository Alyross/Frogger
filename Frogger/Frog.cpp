#include "Frog.h"

const float Frog::speed = 32.0f;

Frog::Frog()
	: Sprite(FROG_PATH)
	, currentPos(2.f)
{
	rect = Rectangle(0, 0, 22, 20);
}


Frog::~Frog()
{
}

void Frog::Update()
{
	//Movement inputs for the frog
	//Prévient l'utilisation des diagonales
	Vector2D dir = {
		cInput->IsKeyPressed(SDL_SCANCODE_LEFT) &&
			(!cInput->IsKeyPressed(SDL_SCANCODE_UP) &&
				!cInput->IsKeyPressed(SDL_SCANCODE_DOWN)) ? -1 : 0 + // for X movements
		cInput->IsKeyPressed(SDL_SCANCODE_RIGHT) &&
			(!cInput->IsKeyPressed(SDL_SCANCODE_UP)) &&
				!cInput->IsKeyPressed(SDL_SCANCODE_DOWN) ? 1 : 0
		,
		cInput->IsKeyPressed(SDL_SCANCODE_UP) ? -1 : 0 + // for Y movements
		cInput->IsKeyPressed(SDL_SCANCODE_DOWN) ? 1 : 0
	};

	//normalize le vecteur pour appliquer le mouvement des différents inputs
	if (Normalize(&dir))
	{
		SetPosition(Add(&GetPosition(), &Scale(&dir, speed)));
	}

	rect.SetPosition(GetX(), GetY());
} 