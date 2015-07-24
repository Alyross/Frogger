#include "Log.h"

//texture paths
std::string Log::LOG_SMALL_PATH = "Images/SmallLog.png";
std::string Log::LOG_MEDIUM_PATH = "Images/MediumLog.png";
std::string Log::LOG_LARGE_PATH = "Images/LargeLog.png";
std::string Log::TURTLE_PATH = "Images/Turtle.png";
std::string Log::VICTORY_PATH = "Images/Victory.png";
//constructeur par défaut
Log::Log()
{
}

//constructeur paramétré
Log::Log(LOG_TYPE logType, int direction, int edge, int width, int height)
	: speed(1.0f)
	, direction(direction)
	, edge(edge)
	, width(width)
	, height(height)
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
	case Log::VICTORY:
		SetTexture(&VICTORY_PATH);
		break;

	default:
		break;
	}

	//set rectangle of logs for collision purposes
	rect = Rectangle(GetX(), GetY(), width, height);
}

Log::~Log()
{
}

//Update move function 
void Log::Update()
{
	Log::Move();
}

//Logs movement function 
void Log::Move()
{
	SetPosition(GetX() + speed * direction, GetY());
	if (GetX() >= maxWidth || GetX() <= minWidth)
	{
		SetPosition(edge, GetY());
	}

	rect.SetPosition(GetX(), GetY());
}