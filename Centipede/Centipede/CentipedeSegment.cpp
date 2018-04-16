#include "stdafx.h"
#include "CentipedeSegment.h"
#include "CentipedeGame.h"
#include "Mushroom.h"
#include <math.h>


CentipedeSegment::CentipedeSegment(sf::RenderWindow * renderWindow, int x, int y, CentipedeSegment* _previous) : GameObject(renderWindow, x,  y)
{
	pointValue = 10;
	health = 1;
	isPoisoned = false;

	setTexture("../Sprites/CentipedeSegment/default.png");

	velocity = sf::Vector2i(1, 0);

	movingDown = movingRight = true;

	previous = _previous;
}


CentipedeSegment::~CentipedeSegment()
{
}

bool CentipedeSegment::canMoveTo(int x, int y) {
	return !CentipedeGame::isMushroomCell(x, y) && x >= 0 && x <= 29 && y >= 0 && y <= 29;
}


void CentipedeSegment::update()
{

	if (CentipedeGame::clock % 8 == 0) {

		calculateVelocity();

		//update position
		currentPosition.x += velocity.x;
		currentPosition.y += velocity.y;

		//update velocity for next movement
	}

}


void CentipedeSegment::collideWith(GameObject * other)
{
	if (dynamic_cast<Bullet *>(other) != nullptr)
		health = 0;
}

unsigned int CentipedeSegment::die(bool &readyToDie) {
	readyToDie = true;

	CentipedeGame::placeObject(currentPosition.x, currentPosition.y, new Mushroom(window, currentPosition.x, currentPosition.y));

	std::cout << "rip centipede segment_______________________________________\n";

	if (previous != nullptr)
		previous->setAsHead();

	return pointValue;
}

void CentipedeSegment::setAsHead() {
	setTexture("../Sprites/CentipedeSegment/head.png");
}

void CentipedeSegment::calculateVelocity() {
	if (velocity.y != 0) { //i changed rows

		if (velocity.y > 0)
			movingDown = true;
		else
			movingDown = false;

		velocity.y = 0; //velocity.x and velocity.y are mutually exclusive

		velocity.x = pow(-1, movingRight);
		movingRight = !movingRight; //flip x directions
	}

	if (!canMoveTo(currentPosition.x + velocity.x, currentPosition.y + velocity.y)) {
		if (currentPosition.y == 0) { //top
			velocity.y = 1; // will cause movingDown to be true next cycle
		}
		else if (currentPosition.y == 29) { //bottom
			velocity.y = -1; //will cause movingDown to be false next cycle
		}
		else { //side or mushroom
			velocity.y = pow(-1, !movingDown);
		}

		velocity.x = 0; //velocity.x and velocity.y are mutually exclusive
	}
}