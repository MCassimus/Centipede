#pragma once
#include "GameObject.h"
#include "Bullet.h"

class Player : public GameObject
{
public:
	Player(int, int);
	void update(CentipedeGame *gameHandle);
	char* getType() { return "Player"; }
	void collideWith(GameObject *);
protected:
	std::shared_ptr<Bullet> bullet;
};