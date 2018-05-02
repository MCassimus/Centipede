#pragma once
#include <SFML\Audio.hpp>
#include "GameObject.h"


class Mushroom: public GameObject
{
public:
	Mushroom(sf::RenderWindow*, int, int);
	//Mushroom(sf::RenderWindow*, sf::Vector2f);
	~Mushroom();
	void update();
	bool getPoisoned();
	bool resetHeath();
	void collideWith(GameObject*);
	char* getType();
	static int color;
private:
	bool poisoned;
};