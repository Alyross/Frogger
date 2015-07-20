#include <iostream>
#include "Engine.h"
#include "Game.h"


int main(int argc, char* args[])
{
	//Initialise la fenêtre de jeu avec les bonnes dimensions
	Engine::GetInstance()->Init(450, 435);

	//Commence le jeu
	Game* game = new Game();

	//Start l'engin(la boucle de jeu)
	Engine::GetInstance()->Start();

	delete game;

	return 0;
}



