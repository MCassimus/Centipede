#pragma once
#include "GameObject.h"


class Mushroom: public GameObject
{
public:
	Mushroom(sf::RenderWindow *);
	~Mushroom();
	void update();
	bool getPoisoned();
private:
	int pointValue;
	bool poisoned;
	int health;
};