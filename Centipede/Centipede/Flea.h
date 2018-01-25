#pragma once
#include "GameObject.h"


class Flea : public GameObject
{
public:
	Flea(sf::RenderWindow *);
	~Flea();
	void update();
private:
	int points;
};