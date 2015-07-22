#include "Game.h"

Game::Game()
{
	Sprite* background = new Sprite("Images/Background.bmp");
	background->SetPosition(0, 0);

	Frog* frog = new Frog();
	frog->SetPosition(225, 405);

	//Spawn cars
	SpawnCarLane(Car::RED, 282, 115, 4, 1, -25);
	SpawnCarLane(Car::YELLOW, 375, 115, 5, -1, 475);
	SpawnCarLane(Car::GREEN, 345, 115, 4, 1, -25);
	SpawnCarLane(Car::BLUE, 315, 115, 5, -1, 475);
	SpawnCarLane(Car::TRUCK, 252, 115, 4, -1, 485);

	//Spawn Logs and turtlesk
	SpawnLogLane(Log::LARGE, 180, 195, 3, 1, -100);
	SpawnTurtleLane(Log::TURTLE, 150, 27, 140, 4, 3, -1, 475);
	SpawnLogLane(Log::MEDIUM, 120, 150, 3, 1, -65);
	SpawnTurtleLane(Log::TURTLE, 90, 27, 145, 4, 2, -1, 475);
	SpawnLogLane(Log::SMALL, 60, 111, 5, 1, -50);
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

void Game::SpawnTurtleLane(Log::LOG_TYPE type, int y, int minOffsetX, int offsetX, int nbStack, int nbTurtle, int direction, int edge)
{
	for (int i = 0; i < nbStack; i++)
	{
		for (int j = 0; j < nbTurtle; j++)

		{
			Log* tempTurtle = new Log(type, direction, edge);
			logs.push_back(tempTurtle);
			tempTurtle->SetPosition(j * minOffsetX + i * offsetX, y);
		}
	}
}

