#pragma once
#include "GameObject.h"


class CentipedeSegment: public GameObject
{
public:
	CentipedeSegment(sf::RenderWindow *, int, int);
	~CentipedeSegment();
	void update();
private:
	int pointValue;
	int dir;
	bool isHead;
};