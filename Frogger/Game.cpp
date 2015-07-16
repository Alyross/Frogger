#include "Game.h"

Game::Game()
{
	Sprite* background = new Sprite("Images/Background.bmp");
	background->SetPosition(0, 0);

	Frog* frog = new Frog();
	frog->SetPosition(225, 405);

	Frog* frog2 = new Frog();
	frog2->SetPosition(225, 375);

	Car* red1 = new Car(Car::RED);
	red1->SetPosition(0, 380);

	Car* 

	//Car* c = new Car(Car::CAR_TYPE::BLUE);
}

Game::~Game()
{
}
