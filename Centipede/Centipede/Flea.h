#pragma once
#include "GameObject.h"


class Flea : public GameObject
{
public:
	Flea();
	Flea(int, int);
	~Flea();
	void update(CentipedeGame*);
	void collideWith(GameObject * other);
	char* getType() { return "Flea"; }
private:
	unsigned int delay = 6;
};