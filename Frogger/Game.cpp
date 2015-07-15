#include "Game.h"

Game::Game()
{
	Sprite* background = new Sprite("Images/Background.bmp");
	background->SetPosition(0, 0);

	Frog* frog = new Frog();
	frog->SetPosition(300, 300);

	//Car* c = new Car(Car::CAR_TYPE::BLUE);
}

Game::~Game()
{
}
