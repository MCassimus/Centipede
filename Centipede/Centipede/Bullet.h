#pragma once
#include "GameObject.h"
#include <iostream>


class Bullet: public GameObject
{
public:
	Bullet(sf::RenderWindow * renderWindow, int, int);
	~Bullet();
	void update();
	void collideWith(GameObject*);
	//bool isAlive();
	//void shootFrom(sf::Vector2i);
	unsigned int die(bool&);
	//char* getType();
	static bool liveBullet;
private:
	int delay = 1;
};