#include "Game.h"

Game::Game()
{
	Sprite* background = new Sprite("Images/Background.bmp");
	background->SetPosition(0, 0);

	Frog* frog = new Frog();
	frog->SetPosition(225, 405);

	//Spawn cars
	SpawnCarLane(Car::RED, 282, 115, 5, 1, 0);
	SpawnCarLane(Car::YELLOW, 375, 115, 5, -1, 450);
	SpawnCarLane(Car::GREEN, 345, 115, 5, 1, 0);
	SpawnCarLane(Car::BLUE, 315, 115, 5, -1, 450);
	SpawnCarLane(Car::TRUCK, 252, 115, 4, -1, 450);

	//Spawn Logs and turtles
	SpawnLogLane(Log::LARGE, 180, 150, 3, 1, 0);
	SpawnLogLane(Log::TURTLE, 150, 25, 10, -1, 450);
	SpawnLogLane(Log::MEDIUM, 120, 115, 4, 1, 0);
	SpawnLogLane(Log::TURTLE, 90, 50, 5, -1, 450);
	SpawnLogLane(Log::SMALL, 60, 180, 6, 1, 0);
}

Game::~Game()
{
}


void Game::SpawnCarLane(Car::CAR_TYPE type, int y, int offsetX, int nbCar, int direction, int edge)
{
	for (int i = 0; i < nbCar; i++)
	{
		Car* tempCar = new Car(type, direction, edge);
		cars.push_back (tempCar);
		tempCar->SetPosition(i * offsetX, y);
	}
}

void Game::SpawnLogLane(Log::LOG_TYPE type, int y, int offsetX, int nbLog, int direction, int edge)
{
	for (int i = 0; i < nbLog; i++)
	{
		Log* tempLog = new Log(type, direction, edge);
		logs.push_back(tempLog);
		tempLog->SetPosition(i * offsetX, y);
	}
}