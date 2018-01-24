#pragma once
#include "GameObject.h"

class Flea : public GameObject
{
public:
	Flea();
	~Flea();
	void update();
private:
	int points;
};