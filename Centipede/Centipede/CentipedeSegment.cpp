#include "stdafx.h"
#include "CentipedeSegment.h"


CentipedeSegment::CentipedeSegment(sf::RenderWindow * renderWindow, int x, int y) : GameObject(renderWindow, x,  y)
{
	pointValue = 10;
	isHead = false;

	setTexture("../Sprites/centipedeSegment.png");

	velocity = sf::Vector2i(rand() % 2 == 1 ? -1 : 1, 0);

}


CentipedeSegment::~CentipedeSegment()
{
}


void CentipedeSegment::update()
{
	if (currentPosition.x == 0 || currentPosition.x == 29)
	{
		currentPosition.y += 1;
		velocity.x *= -1;
	}

	if (isHead)
		setTexture("../Sprites/centipedeHead.png");
	return;
}