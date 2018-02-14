#pragma once
#include "GameObject.h"


class Bullet: public GameObject
{
public:
	Bullet(sf::RenderWindow * renderWindow);
	~Bullet();
};

