#include "Car.h"

std::string Car::CAR_RED_PATH = "Images/CarRed.png";
std::string Car::CAR_BLUE_PATH = "Images/CarBlue.png";
std::string Car::CAR_GREEN_PATH = "Images/CarGreen.png";
std::string Car::CAR_YELLOW_PATH = "Images/CarYellow.png";
std::string Car::CAR_TRUCK_PATH = "Images/CarTruck.png";

//constructeur par défaut
Car::Car()
{
}

//constructeur paramétré 
Car::Car(CAR_TYPE type, int direction, int edge)
	: speed(1.0f)
	, direction(direction)
	, edge(edge)
{
	//Set les textures pour chaque type de Car
	switch (type)
	{
	case Car::RED:
		SetTexture(&CAR_RED_PATH);
		break;
	case Car::BLUE:
		SetTexture(&CAR_BLUE_PATH);
		break;
	case Car::GREEN:
		SetTexture(&CAR_GREEN_PATH);
		break;
	case Car::YELLOW:
		SetTexture(&CAR_YELLOW_PATH);
		break;
	case Car::TRUCK:
		SetTexture(&CAR_TRUCK_PATH);
		break;
	default:
		break;
	}
}

Car::~Car()
{
}

void Car::Update()
{
	Move();
}

//Mouvement pour les cars
void Car::Move()
{
	SetPosition(GetX() + speed * direction, GetY());
	if (GetX() >= maxWidth || GetX() <= minWidth)
	{
		SetPosition(edge, GetY());
	}
}
