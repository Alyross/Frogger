#include "Game.h"

Game::Game()
{
	Sprite* background = new Sprite("Images/Background.bmp");
	background->SetPosition(0, 0);

	Frog* frog = new Frog();
	frog->SetPosition(225, 405);

	SpawnLane(Car::RED, 275, 115, 5, 1, 450);
	SpawnLane(Car::YELLOW, 375, 115, 5, -1, 0);
	SpawnLane(Car::GREEN, 345, 115, 5, 1, 450);
	SpawnLane(Car::BLUE, 315, 115, 5, -1, 0);
	SpawnLane(Car::TRUCK, 252.5, 115, 3, -1, 0);
}

Game::~Game()
{
}


void Game::SpawnLane(Car::CAR_TYPE type, int y, int offsetX, int nbCar, int direction, int edge)
{
	for (int i = 0; i < nbCar; i++)
	{
		Car* temp = new Car(type, direction, edge);
		cars.push_back (temp);
		temp->SetPosition(i * offsetX, y);
	}
}