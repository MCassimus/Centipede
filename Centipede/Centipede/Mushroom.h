#pragma once
#include "GameObject.h"


class Mushroom: public GameObject
{
public:
	Mushroom(sf::RenderWindow*, int, int);
	//Mushroom(sf::RenderWindow*, sf::Vector2f);
	~Mushroom();
	void update();
	bool getPoisoned();
	void resetHeath();
	void collideWith(GameObject*);
	char* getType();
private:
	bool poisoned;
};