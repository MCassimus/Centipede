#pragma once
#include "GameObject.h"
#include <iostream>


class Bullet: public GameObject
{
public:
	Bullet(sf::RenderWindow * renderWindow, int, int);
	void update();
	void collides(GameObject*);
	bool isActive();
	void goToPosition(sf::Vector2i);
	void render();
private:
	bool activity;
};

