#pragma once
#include "GameObject.h"


class CentipedeSegment: public GameObject
{
public:
	CentipedeSegment(sf::RenderWindow *, int, int);
	~CentipedeSegment();
	void update();
	void collideWith(GameObject *);
private:
	bool isPoisoned;
	bool isHead;
};