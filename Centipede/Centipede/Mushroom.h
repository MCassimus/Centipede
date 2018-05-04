#pragma once
#include <SFML\Audio.hpp>
#include "GameObject.h"


class Mushroom : public GameObject
{
public:
	Mushroom(int, int);
	~Mushroom();
	void update(CentipedeGame *gameHandle);
	bool getPoisoned();
	bool resetHeath();
	void collideWith(GameObject*);
	char* getType();
private:
	bool poisoned;
};