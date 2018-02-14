#pragma once
#include "GameObject.h"


class Bullet: public GameObject
{
public:
	Bullet(sf::RenderWindow * renderWindow);
	void update();
	void collides(GameObject*);
	~Bullet();
};

