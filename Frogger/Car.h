#pragma once

#include "Obstacle.h"

class Car :
	public Obstacle
{
public:
	enum CAR_TYPE { RED, BLUE, GREEN, YELLOW, TRUCK };

	Car();
	Car(CAR_TYPE type, int direction, int edge, int width, int height);
	~Car();

	void Update();

	Rectangle GetRect(){ return rect; }

private:
	static std::string CAR_RED_PATH;
	static std::string CAR_BLUE_PATH;
	static std::string CAR_GREEN_PATH;
	static std::string CAR_YELLOW_PATH;
	static std::string CAR_TRUCK_PATH;

	void Move();

	float speed;
	int direction;
	int edge;

	int width;
	int height;

	Rectangle rect;
};

