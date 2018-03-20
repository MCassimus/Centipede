#pragma once
#include "GameObject.h"
#include <iostream>


class Bullet: public GameObject
{
public:
	Bullet(sf::RenderWindow * renderWindow);
	void update();
	void collideWith(GameObject*);
	bool isAlive();
	void shootFrom(sf::Vector2i);
	void die(GameObject*);
private:
	int delay = 1;
};