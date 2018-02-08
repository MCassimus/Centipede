#pragma once
#include "GameObject.h"


class Scorpion: public GameObject
{
public:
	Scorpion(sf::RenderWindow *);
	~Scorpion();
	void update();
private:
	int pointValue;
};