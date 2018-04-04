#pragma once
#include "GameObject.h"


class CentipedeSegment: public GameObject
{
public:
	CentipedeSegment(sf::RenderWindow *, int, int);
	~CentipedeSegment();
	void update();
	void collideWith(GameObject *);
	bool canMoveTo(int, int);

	void updateVelocityTo(int x, int y);
private:
	bool isPoisoned;
	bool isHead;
	bool movingDown, movingRight;
};