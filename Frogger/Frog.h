#pragma once
#include "Sprite.h"

#define FROG_PATH "Images/Frog.png"

class Frog :
	public Sprite
{
public:
	Frog();
	~Frog();

	void Update();
	Rectangle GetRect(){ return rect; }
	void SetActive(bool isActive){ this->isActive = isActive; }
	void SetMatchingSpeed(float speed) { matchingSpeed = speed; }

private:
	bool isActive;
	float matchingSpeed;

	Rectangle rect;

	static const float speed;
};

