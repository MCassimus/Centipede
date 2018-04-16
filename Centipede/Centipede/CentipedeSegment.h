#pragma once
#include "GameObject.h"


class CentipedeSegment: public GameObject
{
public:
	CentipedeSegment(sf::RenderWindow *, int, int, CentipedeSegment*);
	~CentipedeSegment();
	void update();
	void collideWith(GameObject *);
	bool canMoveTo(int, int);

	void setAsHead();

	void calculateVelocity();

	char* getType() { return "CentipedeSegment"; }

	unsigned int die(bool&);

private:
	bool isPoisoned;
	bool movingDown, movingRight;
	CentipedeSegment * previous;
};