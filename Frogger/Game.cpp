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
	red1->SetPosition(0, 290);

	Car* yellow1 = new Car(Car::YELLOW);
	yellow1->SetPosition(0, 380);

	Car* green1 = new Car(Car::GREEN);
	green1->SetPosition(0, 350);

	Car* blue1 = new Car(Car::BLUE);
	blue1->SetPosition(0, 320);

	Car* truck1 = new Car(Car::TRUCK);
	truck1->SetPosition(0, 260);
}

Game::~Game()
{
}
