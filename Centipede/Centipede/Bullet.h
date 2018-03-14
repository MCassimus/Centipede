#pragma once
#include "GameObject.h"
#include <iostream>


class Bullet: public GameObject
{
public:
	Bullet(sf::RenderWindow * renderWindow, int, int);
	void update();
	void collideWith(GameObject*);
	bool isActive();
	void shootFrom(sf::Vector2i);
private:
	bool activity;
	int delay = 1;
};