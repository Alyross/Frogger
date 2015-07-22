#include "Log.h"

std::string Log::LOG_SMALL_PATH = "Images/SmallLog.png";
std::string Log::LOG_MEDIUM_PATH = "Images/MediumLog.png";
std::string Log::LOG_LARGE_PATH = "Images/LargeLog.png";
std::string Log::TURTLE_PATH = "Images/Turtle.png";

Log::Log()
{
}

Log::Log(LOG_TYPE logType, int direction, int edge)
	: speed(1.0f)
	, direction(direction)
	, edge(edge)
{
	//Set les textures pour les logs et tortues
	switch (logType)
	{
	case Log::SMALL:
		SetTexture(&LOG_SMALL_PATH);
		break;
	case Log::MEDIUM:
		SetTexture(&LOG_MEDIUM_PATH);
		break;
	case Log::LARGE:
		SetTexture(&LOG_LARGE_PATH);
		break;
	case Log::TURTLE:
		SetTexture(&TURTLE_PATH);
		break;

	default:
		break;
	}
}

Log::~Log()
{
}

void Log::Update()
{
	Log::Move();
}

//Mouvement pour les Logs
void Log::Move()
{
	SetPosition(GetX() + speed * direction, GetY());
	if (GetX() >= maxWidth || GetX() <= minWidth)
	{
		SetPosition(edge, GetY());
	}
}