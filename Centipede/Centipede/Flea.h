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
private:
	unsigned int delay = 6;
};