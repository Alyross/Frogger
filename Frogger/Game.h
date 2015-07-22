#pragma once

#include "Car.h"
#include "Frog.h"
#include "Log.h"

class Game :
	public Component
{
public:
	Game();
	~Game();

private: 
	//Spawning obstacle functions
	void SpawnCarLane(Car::CAR_TYPE type, int y, int offsetX, int nbCar, int direction, int edge);
	void SpawnLogLane(Log::LOG_TYPE logType, int y, int offsetX, int nbLog, int direction, int edge);
	void SpawnTurtleLane(Log::LOG_TYPE logType, int y, int minOffsetX, int offsetX, int nbStack, int nbTurtle, int direction, int edge);

	//Frog movements input functions
	void KeyMovements();

	std::vector<Car*> cars;
	std::vector<Log*> logs;
};

