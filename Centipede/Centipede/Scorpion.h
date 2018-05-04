#pragma once
#include "GameObject.h"


class Scorpion : public GameObject
{
public:
	Scorpion(int, int);
	void update(CentipedeGame *gameHandle);
	void collideWith(GameObject*);
	char* getType() { return "Scorpion"; }
private:
	int scuttle; // for walking animation

	unsigned int frameMax = 40;
};