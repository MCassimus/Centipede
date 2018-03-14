#pragma once
#include "GameObject.h"
#include "Bullet.h"

class Player : public GameObject
{
public:
	Player(sf::RenderWindow *, int, int);
	void update();
	void render();
	~Player();
protected:
	Bullet bullet;
};