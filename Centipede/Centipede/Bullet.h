#pragma once
#include "GameObject.h"
#include <iostream>


class Bullet : public GameObject
{
public:
	Bullet(int, int);
	~Bullet();
	void update();
	void collideWith(GameObject*);
	//bool isAlive();
	//void shootFrom(sf::Vector2i);
	unsigned int die(bool&, CentipedeGame*);
	char* getType() { return "Bullet"; }
	static bool liveBullet;
private:
	int delay = 1;
};