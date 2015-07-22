#pragma once

#include "Obstacle.h"

class Log :
	public Obstacle
{
public:
	enum LOG_TYPE { SMALL, MEDIUM, LARGE, TURTLE };

	Log();
	Log(LOG_TYPE type, int direction, int edge);
	~Log();

	void Update();

private: 
	static std::string LOG_SMALL_PATH;
	static std::string LOG_MEDIUM_PATH;
	static std::string LOG_LARGE_PATH;
	static std::string TURTLE_PATH;

	void Move();

	float speed;
	int direction;
	int edge;
};

