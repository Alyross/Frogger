#include <iostream>
#include "Engine.h"
#include "Game.h"

// h
class A
{
public:
	A();
	A(int i);
	~A();

	int i;
};

// cpp
A::A(): i(0) {}
A::A(int i) : i(i) {}
A::~A(){}

class B: public A
{
public:
	B();
	~B();

	int bibi;
};

B::B(): A(5) {}
B::~B(){}

class C : public A
{
public:
	C();
	~C();

	int cici;
};

C::C() : A(5) {}
C::~C(){}


int main(int argc, char* args[])
{
	std::vector<A*> v = std::vector<A*>(3);
	v[0] = new B();
	v[1] = new C();
	v[2] = new C();

	for (int i = 0; i < v.size(); i++)
	{
		// upcast
		std::cout << ((B*)v[i])->bibi << std::endl;
	}

	//Initialise la fenêtre de jeu avec les bonnes dimensions
	Engine::GetInstance()->Init(450, 435);

	//Commence le jeu
	Game* game = new Game();

	//Start l'engin(la boucle de jeu)
	Engine::GetInstance()->Start();

	delete game;

	return 0;
}



