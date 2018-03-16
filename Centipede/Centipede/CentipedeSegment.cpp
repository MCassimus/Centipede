#include "stdafx.h"
#include "CentipedeSegment.h"
#include "CentipedeGame.h"
#include "Mushroom.h"


CentipedeSegment::CentipedeSegment(sf::RenderWindow * renderWindow, int x, int y) : GameObject(renderWindow, x,  y)
{
	pointValue = 10;
	isHead = true;

	setTexture("../Sprites/centipedeSegment.png");

	velocity = sf::Vector2i(rand() % 2 == 1 ? -1 : 1, 0);
	if (velocity.x < 0)
		object.rotate(90);
	else
		object.rotate(-90);
}


CentipedeSegment::~CentipedeSegment()
{
}


void CentipedeSegment::update()
{
	if (CentipedeGame::clock % 2 == 0)
	{
		if (currentPosition.x == 0 || currentPosition.x == 29)
		{
			velocity.x *= -1;
			currentPosition.y++;
			//object.setScale(-object.getScale());
			//object.rotate(180);
		}

		currentPosition.x += velocity.x;
		currentPosition.y += velocity.y;

		//system("pause");

		////if at edge of screen flip dir and go down
		//if (currentPosition.x == 0 || currentPosition.x == 29)
		//{
		//	currentPosition.y += 1;
		//	velocity.x *= -1;
		//	object.setScale(-object.getScale());
		//}
		////check mushroom collision from next cell
		//else if (CentipedeGame::isMushroomCell(currentPosition.x + velocity.x, currentPosition.y + velocity.y))
		//{
		//	currentPosition.y += 1;
		//	velocity.x *= -1;
		//	object.setScale(-object.getScale());
		//}

		////apply velocity
		//currentPosition.x += velocity.x;
		//currentPosition.y += velocity.y;

		//if(velocity.y != 0 && currentPosition.y == 17)
		//	velocity = sf::Vector2i(rand() % 2 == 1 ? -1 : 1, 0);
		//
		//printf("%i %i\n", currentPosition.x, currentPosition.y);
	}

	if (isHead)
		setTexture("../Sprites/centipedeHead.png");
}


void CentipedeSegment::collideWith(GameObject * other)
{
	/*if (dynamic_cast<Mushroom *>(other) != nullptr)
	{
		if (dynamic_cast<Mushroom *>(other)->getPoisoned())
			velocity = sf::Vector2i(0, 1);
	}*/
}