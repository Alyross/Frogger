#pragma once

#include "Car.h"
#include "Frog.h"
#include "Log.h"
#include "Victory.h"

class Game :
	public Component
{
public:
	Game();
	~Game();

	void Update();

private: 
	//Spawning obstacle functions
	void SpawnCarLane(Car::CAR_TYPE type, int y, int offsetX, int nbCar, int direction, int edge, int width, int height);
	void SpawnLogLane(Log::LOG_TYPE logType, int y, int offsetX, int nbLog, int direction, int edge, int width, int height);
	void SpawnTurtleLane(Log::LOG_TYPE logType, int y, int minOffsetX, int offsetX, int nbStack, int nbTurtle, int direction, int edge, int width, int height);
	
	float CheckIsSafe();

	//Frog movements input functions
	void VictoryConditions();

	std::vector<Car*> cars;
	std::vector<Log*> logs;
	std::vector<Frog*> frogs;
	std::vector<Victory*> victoryFrogs;

	int currentFrog;
	int frogsCreated;
	int nbFrogs;
	int currentVictoryFrog;

	Sprite* startScreen;
	Sprite* blackScreen;
};

