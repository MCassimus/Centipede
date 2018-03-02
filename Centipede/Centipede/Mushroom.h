#pragma once
#include "GameObject.h"


class Mushroom: public GameObject
{
public:
	Mushroom(sf::RenderWindow*);
	~Mushroom();
	void update();
	bool getPoisoned();
	void resetHeath();
	void collides(GameObject*);
private:
	int pointValue;
	bool poisoned;
};