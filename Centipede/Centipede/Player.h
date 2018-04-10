#pragma once
#include "GameObject.h"
#include "Bullet.h"

class Player : public GameObject
{
public:
	Player(sf::RenderWindow *, int, int);
	void update();
	~Player();
	char* getType();
	void collideWith(GameObject *);
protected:
	Bullet * bullet = nullptr;
};