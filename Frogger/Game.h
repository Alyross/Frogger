#pragma once

#include "Car.h"
#include "Frog.h"

class Game :
	public Component
{
public:
	Game();
	~Game();

private: 
	void SpawnLane(Car::CAR_TYPE type, int y, int offsetX, int nbCar, int direction, int edge);

	std::vector<Car*> cars;
};

