#pragma once
#include "GameObject.h"


class CentipedeSegment: public GameObject
{
public:
	CentipedeSegment();
	CentipedeSegment(sf::RenderWindow *, int, int);
	~CentipedeSegment();

	void attach(CentipedeSegment*);

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
	CentipedeSegment * previous = nullptr;
};