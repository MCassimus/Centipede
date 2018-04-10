#pragma once
#include "GameObject.h"


class Flea : public GameObject
{
public:
	Flea();
	Flea(sf::RenderWindow *, int, int);
	~Flea();
	void update();
	void collideWith(GameObject * other);
	char* getType() { return "Flea"; }
private:
	int points;
	unsigned int delay = 6;
};