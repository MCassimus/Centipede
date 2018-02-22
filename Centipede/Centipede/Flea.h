#pragma once
#include "GameObject.h"


class Flea : public GameObject
{
public:
	Flea();
	Flea(sf::RenderWindow *);
	~Flea();
	void update();
private:
	int points;
	unsigned int delay = 50;
};