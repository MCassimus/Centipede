#pragma once
#include "GameObject.h"
#include "Bullet.h"

class Player : public GameObject
{
public:
	Player(sf::RenderWindow *, int, int);
	void update();
	~Player();
protected:
	Bullet bullet;
};