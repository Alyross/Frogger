#include "Frog.h"

const float Frog::speed = 32.0f;

Frog::Frog()
	: Sprite(FROG_PATH)
	, isActive(false)
	, matchingSpeed(0.f)
{
	rect = Rectangle(GetX(), GetY(), 22, 20);
}

Frog::~Frog()
{
}

void Frog::Update()
{
	if (isActive)
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
		SetPosition(GetX() + matchingSpeed, GetY());
		rect.SetPosition(GetX() + matchingSpeed, GetY());
	}
} 