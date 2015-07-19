#include "Game.h"

Game::Game()
{
	Sprite* background = new Sprite("Images/Background.bmp");
	background->SetPosition(0, 0);

	Frog* frog = new Frog();
	frog->SetPosition(225, 405);

	Car* red1 = new Car(Car::RED);
	red1->SetPosition(0, 285);

	Car* yellow1 = new Car(Car::YELLOW);
	yellow1->SetPosition(0, 375);

	Car* green1 = new Car(Car::GREEN);
	green1->SetPosition(0, 345);

	Car* blue1 = new Car(Car::BLUE);
	blue1->SetPosition(0, 315);

	Car* truck1 = new Car(Car::TRUCK);
	truck1->SetPosition(410, 252.5);
}

Game::~Game()
{
}
