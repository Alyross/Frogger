#include "Game.h"

//constructeur par défaut
Game::Game()
	: currentFrog(0)
	, frogsCreated(5)
	, nbFrogs(4)
	, currentVictoryFrog(0)
{
	//Spawn the background of the game
	Sprite* background = new Sprite("Images/Background.bmp");
	background->SetPosition(0, 0);
	
	//Spawn cars
	SpawnCarLane(Car::RED, 282, 115, 4, 1, -25, 24, 20);
	SpawnCarLane(Car::YELLOW, 375, 115, 5, -1, 475, 22, 20);
	SpawnCarLane(Car::GREEN, 345, 115, 4, 1, -25, 23, 20);
	SpawnCarLane(Car::BLUE, 315, 115, 5, -1, 475, 25, 20);
	SpawnCarLane(Car::TRUCK, 252, 115, 5, -1, 485, 35, 20);

	//Spawn Logs and turtlesk
	SpawnLogLane	(Log::LARGE, 180, 195, 3, 1, -100, 100, 20);
	SpawnTurtleLane	(Log::TURTLE, 150, 27, 140, 4, 3, -1, 475, 25, 20);
	SpawnLogLane	(Log::MEDIUM, 120, 150, 3, 1, -65, 65, 20);
	SpawnTurtleLane	(Log::TURTLE, 90, 27, 145, 4, 2, -1, 475, 25, 20);
	SpawnLogLane	(Log::SMALL, 60, 111, 5, 1, -50, 50, 20);

	//Spawn the frog player and the nenuphar/victoryfrogs and sets them invisible until a collision with the player occurs
	for (int i = 0; i < frogsCreated; i++)
	{
		Frog* frog = new Frog();
		frog->SetPosition(218, 410);
		frogs.push_back(frog);

		int startX = 23;
		int offsetX = 98;

		Victory* victoryFrog = new Victory(20, 20);
		victoryFrog->SetVisible(false);
		victoryFrog->SetPosition(startX + i * offsetX, 20);
		victoryFrogs.push_back(victoryFrog);
	}

	frogs[currentFrog]->SetVisible(true);
	frogs[currentFrog]->SetActive(true);

	//Starting Screen
	blackScreen = new Sprite("Images/blackScreen.png");
	startScreen = new Sprite("Images/StartScreen.png");
	startScreen->SetPosition(125, 205);
}

Game::~Game()
{

}

void Game::Update()
{
	//press spacebar to remove the startscreen and start playing
	if (cInput->IsKeyPressed(SDL_SCANCODE_SPACE))
	{
		startScreen->SetVisible(false);
		blackScreen->SetVisible(false);
	}

	//if frog gets out of window limits
	if (frogs[currentFrog]->GetX() < 0)
	{
		frogs[currentFrog]->SetPosition(0, frogs[currentFrog]->GetY());
	}
	
	if (frogs[currentFrog]->GetX() > 420)
	{
		frogs[currentFrog]->SetPosition(418, frogs[currentFrog]->GetY());
	}

	if (frogs[currentFrog]->GetY() >= 435)
	{
		frogs[currentFrog]->SetPosition(frogs[currentFrog]->GetX(), 408);
	}

	// Collision avec les voitures
	for (int i = 0; i < cars.size(); i++)
	{
		if (frogs[currentFrog]->GetRect().CollidesWith(&cars[i]->GetRect()))
		{
			std::cout << "Your frog Died" << std::endl;
			frogs[currentFrog]->SetVisible(false);
			frogs[currentFrog]->SetActive(false);

			if (currentFrog < nbFrogs)
			{
				currentFrog++;

				frogs[currentFrog]->SetVisible(true);
				frogs[currentFrog]->SetActive(true);
			}
		}
	}

	//if the frog touches the water it dies, if it is on a log or a turtle it will move in their direction at the same speed
	if (frogs[currentFrog]->GetY() < 216 && frogs[currentFrog]->GetY() > 40)
	{
		float speed = CheckIsSafe();

		if (speed == 0.f)
		{
			// Die
			frogs[currentFrog]->SetVisible(false);
			frogs[currentFrog]->SetActive(false);
			frogs[currentFrog]->SetMatchingSpeed(0.f);

			if (currentFrog < nbFrogs)
			{
				currentFrog++;

				frogs[currentFrog]->SetVisible(true);
				frogs[currentFrog]->SetActive(true);
			}
		}
		else
		{
			frogs[currentFrog]->SetMatchingSpeed(speed);
		}
	}
	else
	{
		frogs[currentFrog]->SetMatchingSpeed(0.f);
	}
	
	//Victory Conditions
	if (frogs[currentFrog]->GetY() < 40)
	{
		frogs[currentFrog]->SetVisible(false);
		frogs[currentFrog]->SetActive(false);
		frogs[currentFrog]->SetMatchingSpeed(0.f);

		if (currentFrog < nbFrogs)
		{
			currentFrog++;

			frogs[currentFrog]->SetVisible(true);
			frogs[currentFrog]->SetActive(true);
		}
		for (int i = 0; i < victoryFrogs.size(); i++)
		{
			std::cout << victoryFrogs[i] << std::endl;

			if (frogs[currentFrog]->GetRect().CollidesWith(&victoryFrogs[i]->GetRect()))
			{
				
				std::cout << "collide with fucking victoire" << std::endl;
				victoryFrogs[i]->SetVisible(true);
			}
		}
	}
}

//check if frog is safe when in water zone
float Game::CheckIsSafe()
{
	for (int j = 0; j < logs.size(); j++)
	{
		Rectangle frogRect = frogs[currentFrog]->GetRect();
		Rectangle logRect = logs[j]->GetRect();

		if (frogRect.CollidesWith(&logRect))
		{
			return logs[j]->GetSpeed();
		}
	}
	return 0.0f;
}

void Game::SpawnCarLane(Car::CAR_TYPE type, int y, int offsetX, int nbCar, int direction, int edge, int width, int height)
{
	//Spawn les cars avec la distance "offsetX" qui sépare chaque car.
	for (int i = 0; i < nbCar; i++)
	{
		Car* tempCar = new Car(type, direction, edge, width, height);
		tempCar->SetPosition(i * offsetX, y);
		cars.push_back(tempCar);
	}
}

void Game::SpawnLogLane(Log::LOG_TYPE type, int y, int offsetX, int nbLog, int direction, int edge, int width, int height)
{
	//Spawn les logs avec une distance offsetX entre chaque
	for (int i = 0; i < nbLog; i++)
	{
		Log* tempLog = new Log(type, direction, edge, width, height);
		logs.push_back(tempLog);
		tempLog->SetPosition(i * offsetX, y);
	}
}

void Game::SpawnTurtleLane(Log::LOG_TYPE type, int y, int minOffsetX, int offsetX, int nbStack, int nbTurtle, int direction, int edge, int width, int height)
{
	//Spawn des stacks de tortue avec une distance offsetX entre chaque stack
	for (int i = 0; i < nbStack; i++)
	{
		for (int j = 0; j < nbTurtle; j++)
		{
			Log* tempTurtle = new Log(type, direction, edge, width, height);
			logs.push_back(tempTurtle);
			tempTurtle->SetPosition(i * offsetX + j * minOffsetX, y);
		}
	}
}