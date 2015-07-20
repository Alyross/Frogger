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
	void SpawnCarLane(Car::CAR_TYPE type, int y, int offsetX, int nbCar, int direction, int edge);
	void SpawnLogLane(Log::LOG_TYPE type, int y, int offsetX, int nbCar, int direction, int edge);

	std::vector<Car*> cars;
	std::vector<Log*> logs;
};

