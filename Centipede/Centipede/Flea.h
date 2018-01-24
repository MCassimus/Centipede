#pragma once
#include "GameObject.h"

class Flea : public GameObject
{
public:
	Flea();
	void update();
	~Flea();
private:
	int points
};

